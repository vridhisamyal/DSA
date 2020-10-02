#include<iostream>
using namespace std;

int min_dij(int *p,int *s,int n)
{
  int t=100,t1;

  for(int i=0;i<n;i++)
  {
    if(p[i]<t && p[i]!=0 && s[i]!=1)
       t=p[i],t1=i;;
  }

  if(t==99)
    return -1;
  else
    return t1;
}

// replace int a[][] to int **a if using runtime size

void dijkstra(int a[][9], int *p, int n)
{
  int state[n];
  int l,min_index;
  cout<<endl<<"Enter source vertex [Starting from 0] : ";
  cin>>l;
  min_index=l;
  for(int i=0;i<n;i++)
  {
    if(i==l)
      p[i]=0, state[i]=1;
    else
      p[i]=99, state[i]=0;
  }

  for(int i=0;i<n;i++)
  {
    if(a[l][i]!=0)
    {
      if(a[l][i]+p[l]<p[i])
        p[i]=a[l][i]+p[l];
    }
  }

  for(int lp=1;lp<n;lp++)
  {

    min_index=min_dij(p,state,n);
    state[min_index]=1;

    cout<<min_index<<endl;

    for(int j=0;j<n;j++)
    {
      if(a[min_index][j]!=0 && state[j]!=1)
      {
        if(a[min_index][j]+p[min_index]<p[j])
          p[j]=a[min_index][j]+p[min_index];
      }
    }
  }

  for(int i=0;i<n;i++)
    cout<<state[i]<<" ";
//  cout<<min_index;
  cout<<endl;

}

void disp(int *p, int n)
{
  for(int i=0;i<n;i++)
    cout<<p[i]<<" ";
}

int main()
{
  int n;
  cout<<"No. of vertices : ";
  cin>>n;
  int p[n];

  //int a[4][4]={{0,6,0,0},{0,0,1,5},{2,0,0,2},{0,0,0,0}};

  int a[][9]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
              { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
              { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
              { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
              { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
              { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
              { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
              { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
              { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
/*
  // uncomment this foe runtime allocation
  int **a;

  a=new int*[n];
  for(int i=0;i<n;i++)
    a[i]=new int[n];


  for(int i=0 ; i<n ; i++)
  {
    for(int j=0 ; j<n ; j++)
    {
      if(i!=j)
      {
        cout<<"Enter A"<<i+1<<j+1<<" : ";
        cin>>a[i][j];
      }
      else
        a[i][j]=0;
    }
  }
  */

  dijkstra(a,p,n);
  disp(p,n);

}
