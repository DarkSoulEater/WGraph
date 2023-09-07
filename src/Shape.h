#ifndef ___SHAPE_H___
#define ___SHAPE_H___

class Shape {
public:
    Shape();
    ~Shape();

private:
    virtual void Draw_() = 0;

    Shape* next_ = nullptr;
    Shape* prev_ = nullptr;
    static Shape* Head_; // Ptr to head of Shape list
};

#endif // ___SHAPE_H___