
template<class Type> class List
{
    int count;
    Type *next;
    Type *previous;
    Type *current;
    public:
    List();
    int getCount();
    Type* getnext();
    Type* getPrevious();
    Type* getCurrent();
    ~List();
};
