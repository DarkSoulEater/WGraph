#include "AtomHandler.h"
#include <assert.h>
#include <vector>
#include "Atom.h"
#include "DifficultAtom.h"
#include "SimpleAtom.h"
#include "Event/ProduceEvent.h"
#include <omp.h>

static void GenerateCollision(Atom* atom0, Atom* atom1) {
    
}

void AtomsHandler::CollisionChecking() {
    assert(GetParent());
    std::vector<std::shared_ptr<Event>> events;

    //#pragma omp parallel for
    for (auto& first_widget : widgets_) {
        if (first_widget.use_count() == 0) continue;
        if (!first_widget->IsEnabled()) continue;

        for (auto& second_widget : widgets_) {
            if (!second_widget->IsEnabled()) continue;
            if (first_widget == second_widget) continue;

            if (first_widget->GetGlobalBounds().Intersects(second_widget->GetGlobalBounds())) {
                Atom* atom0 = static_cast<Atom*>(first_widget.get());
                Atom* atom1 = static_cast<Atom*>(second_widget.get());
                
                float speed0 = atom0->GetSpeed();
                float speed1 = atom1->GetSpeed();

                if (atom0->Type() == AtomType::Simple 
                 && atom1->Type() == AtomType::Simple) {
                    if (speed0 + speed1 < kSimpleThresholdSpeed_) {
                        GenerateCollision(atom0, atom1);
                        CollisionSS(static_cast<SimpleAtom*>(atom0), static_cast<SimpleAtom*>(atom1));
                        break;
                    }

                    std::shared_ptr<ProduceEvent> event(new ProduceEvent(AtomType::Difficult));
                    event->Position = (atom0->GetPosition() + atom1->GetPosition()) / 2;
                    events.push_back(event);

                    atom0->SetEnabled(false);
                    atom1->SetEnabled(false);
                    break;
                }

                if (atom0->Type() == AtomType::Difficult 
                 && atom1->Type() == AtomType::Difficult) {
                    if (speed0 + speed1 < kDifficultThresholdSpeed_) {
                        GenerateCollision(atom0, atom1);
                        break;
                    }

                    std::shared_ptr<ProduceEvent> event(new ProduceEvent(AtomType::None));
                    event->Position = (atom0->GetPosition() + atom1->GetPosition()) / 2;
                    event->Explosion = (atom0->GetMass() + atom1->GetMass()) / Atom::kDefMass;
                    events.push_back(event);

                    atom0->SetEnabled(false);
                    atom1->SetEnabled(false);
                    break;
                }

                if (speed0 + speed1 < kMixedThresholdSpeed_) {
                    GenerateCollision(atom0, atom1);
                    break;
                }
                
                if (atom0->Type() == AtomType::Simple) std::swap(atom0, atom1);

                atom0->SetMass(atom0->GetMass() + Atom::kDefMass);
                atom1->SetEnabled(false);
            }
        }
    }

    for (auto& event : events) {
        GetParent()->OnEvent(event.get());
    }
}

void AtomsHandler::CollisionSS(SimpleAtom *atom0, SimpleAtom *atom1) {
    return;
    Vector2 dir = atom1->GetPosition() - atom0->GetPosition();
    Vector2 dir0 = atom0->GetDir();
    Vector2 dir1 = atom1->GetDir();

    float smul = dir0.Dot(dir1);

    atom0->SetDir(-dir0);
    atom1->SetDir(-dir1);

    atom0->SetDir({0, 1});
}
