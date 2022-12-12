#include<iostream>
#include <climits>
using namespace std;
#define N 5

class DVR{
    public:
        int array_connections[N][N];
        int next[N][N];
        int minCost[N][N];

        DVR(int arr[N][N]){
            for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                    array_connections[i][j]=arr[i][j];

                    if(array_connections[i][j]!=0){
                        next[i][j]=j;
                        minCost[i][j]=array_connections[i][j];
                    }
                    else if(i==j){
                        minCost[i][j]=0;
                        next[i][j]=j;
                    }
                    else{
                        next[i][j]=-1;
                        minCost[i][j]=INT_MAX;
                    }
                }
            }
        }

        int implement(){

                for(int i=0 ;i<N ; i++){
                    for(int j=0 ; j<N ; j++){
                        for(int k=0 ; k<N ; k++){
                            if(next[i][j]!=-1 and next[j][k]!=-1 and next[i][k]==-1){
                                if(minCost[i][k]>(minCost[i][j]+minCost[j][k])){
                                    minCost[i][k]=minCost[i][j]+minCost[j][k];
                                    next[i][k]=j;
                                }
                            }
                        }
                    }
                }
            return 0;
        }

        void display(){
            for(int i=0 ; i< N ; i++){
                for(int j=0 ; j<N ; j++){
                    cout<<"From : " << i << " to Dist : " << j << " through : "<< next[i][j] << " in minCost : "<< minCost[i][j]<<endl;
                }
            }
        }


};

int main(){
    
    int arr[N][N]={ {0,4,5,0,0},
                    {4,0,9,3,0},
                    {5,9,0,0,8},
                    {0,3,0,0,2},
                    {0,0,8,2,0} };

    DVR obj(arr);
    obj.implement();
    obj.display();

    return 0;
}