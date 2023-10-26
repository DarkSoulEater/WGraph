#ifndef ___ACTION_H___
#define ___ACTION_H___

class Action {
public:
    Action()  { }
    virtual ~Action() { }

    virtual void operator()() = 0;
};

#endif // ___ACTION_H___