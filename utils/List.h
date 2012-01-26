
template<class Type> class List
{
    int count;
    Type *next;
    Type *previous;
    Type *current;
    public:
    List();
    int getCount();
    void add(Type* obj);
    void remove(Type* obj);
    Type* getnext();
    Type* getPrevious();
    Type* getCurrent();
    ~List();
};
