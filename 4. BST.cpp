#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};
class bstree
{
    public:
    Tree*create(int data)
    {
        Tree*tempTree=new Tree;
        tempTree->left=nullptr;
        tempTree->right=nullptr;
        tempTree->data=data;
        return tempTree;
    }
    void setLeft(Tree*aTree,int data)
    {
        aTree->left=create(data);
    }
    void setRight(Tree*aTree,int data)
    {
        aTree->right=create(data);
    }
    void insert(Tree*aTree,int data)
    {
        while(aTree!=NULL)
        {
            if(data<=aTree->data)
            {
                if(aTree->left!=nullptr)
                {
                    aTree=aTree->left;
                }
                else
                {
                    setRight(aTree,data);
                    break;
                }
            }
            else
            {
                if(aTree->right!=nullptr)
                {
                    aTree=aTree->right;
                }
                else
                {
                    setRight(aTree,data);
                    break;
                }   
            }
        }
    }
    void inordertTraverse(Tree *aTree)
    {
        if(aTree->left!=nullptr)
        inordertTraverse(aTree->left);
        cout<<"\n data :"<<aTree->data;
        if(aTree->right!=nullptr)
        inordertTraverse(aTree->right);
    }
    int height(Tree *aTree)
    {
        int hl,hr;
        if(aTree == nullptr)
        {
            return 0;
        }
        else if(aTree->left==nullptr&& aTree->right==nullptr)
        {
            return 0;
        }
        hr=height(aTree->right);
        hl=height(aTree->left);
        if(hr>hl)
        {
            return(1+hr);
        }
        else
        {
            return(1+hl);
        }
    }
    void swap(Tree *aTree)
    {
        Tree *temp;
        temp=aTree;
        if(aTree !=nullptr)
        {
            swap(aTree->left);
            swap(aTree->right);
            temp=aTree->left;
            aTree->left=aTree->right;
            aTree->right=temp;
        }
    }
    int minValue(Tree *aTree)
    {
        if (aTree->left == NULL)
        return aTree->data;
        return minValue(aTree->left);
    }
    bool search(Tree *aTree,int value)
    {
        if (aTree == NULL)
        {
            return false;
        }
        while (aTree != NULL)
        {
            if (value == aTree->data) 
            {
                return true;
            }
            else if (value < aTree->data)   
            {
                aTree = aTree->left;
            }
            else 
            {
                aTree = aTree->right;
            }
        }
        return false;
    }
};
int main()
{
    bstree bs;
    int ch,value;
    Tree *myTree ;
    while(ch!=8)
    {
        cout<<"\n 1. Create";
        cout<<"\n 2.insert";
        cout<<"\n 3.display";
        cout<<"\n 4.find no of nodes in largest path";
        cout<<"\n 5.find minimum value of tree";
        cout<<"\n 6.swap";
        cout<<"\n 7. Search";
        cout<<"\n 8. Exit";
        cout<<"\n Enter your choice";
        cin>>ch;
        switch (ch)
        {
            case 1:
            cout<<"enter root";
            cin>>value;
            myTree = bs.create(value);
            break;
            case 2:
            cout<<"enter value";
            cin>>value;
            bs.insert(myTree,value);
            break;
            case 3:
            bs.inordertTraverse(myTree);
            break;
            case 4:
            cout<<"\n No of nodes in longest path :"<<(1+bs.height(myTree));
            break;
            case 5:
            cout<<"\n Minimum Data Value found in the tree is :"<<bs.minValue(myTree);
            break;
            case 6: bs.swap(myTree);
            cout<<"\n Tree after swaping:";
            bs.inordertTraverse(myTree);
            break;
            case 7:cout<<"\n Enter the value to search";
            cin>> value;
            if (bs.search(myTree,value)) {
            cout << "Found "<< value<<" in tree" << endl;
        }
        else 
        {
            cout << "Could not find "<<value <<" in tree" << endl;
        }
        break;
        default:
        cout<<"\n Enter valid input";
        break;
    }
}
return 0 ;
}
