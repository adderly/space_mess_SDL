
template <class ID=string,class Type> class ArrayList
{

    int count;
    int index[];

public:
    ArrayList();
    ArrayList(string,Type);
    ArrayList(string[],Type[]);
    int getCount;
    void add(string,Type);
    void remove(string);
    ~ArrayList();
};
