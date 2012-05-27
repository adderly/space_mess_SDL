template<class Type> class List
{
    int count;
    Type *first;
    Type *last;
    Type *current;
public:
    List();
    int getCount();
    void add(Type* obj);
    void remove(Type* obj);
    void Next();
    void Previous();
    Type* getNext();
    Type* getPrevious();
    Type* getCurrent();
    ~List();
};
