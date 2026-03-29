#include <iostream>
using namespace std;
class base
{public:
    int* add(int* n1,int* n2)
    {
      int *ptr=new int(*n1+*n2);
      return ptr;
    }
};
int main()
{
  int *n1=new int(5),*n2=new int(10);
  base b1;
    
  int* sum=b1.add(n1,n2);
  cout << "sum = " << *sum << endl;
  delete sum;
  delete n1;
  delete n2;
  return 0;
}
