#include <iostream>




class tree{
public:
   virtual void draw(){

        std::cout<<" cos tam sobie rysuje"<<std::endl;
    }

    virtual ~tree(){}


};

class treeWithStars : public tree{

 public:

    void draw(){


        std::cout<<" /\\"<<std::endl;
        std::cout<<"/**\\"<<std::endl<<std::endl;


    }



};

class treeWithPluse : public tree{

 public:

    void draw(){


        std::cout<<" /\\"<<std::endl;
        std::cout<<"/++\\"<<std::endl<<std::endl;


    }



};

class treeWithSth : public tree{

 public:

    void draw(){


        std::cout<<" /\\"<<std::endl;
        std::cout<<"//\\\\"<<std::endl<<std::endl;


    }

};





int main()
{
    tree *t1, *t2, *t3;

    treeWithPluse *tp;
    treeWithStars *ts;
    treeWithSth   *tsth;

    t1 = tp = new treeWithPluse();
    t2 = ts = new treeWithStars();
    t3 = tsth = new treeWithSth();

    t1->draw();
    tp->draw();
    t2->draw();
    ts->draw();
    t3->draw();
    tsth->draw();

    delete tp;
    delete ts;
    delete tsth;




    return 0;
}
