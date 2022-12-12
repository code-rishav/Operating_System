#include <iostream>
#include <climits>
#define N 5 
using namespace std;

class Dijkstra {
    public :
        int array_connections[N][N];
        bool visited[N];
        int minCost[N];

        Dijkstra(int arr[N][N]){
            for(int i=0 ; i<N ; i++){
                for(int j=0 ; j<N ; j++){
                    array_connections[i][j]=arr[i][j];
                }
            }

            for(int i=0 ; i<N ; i++){
                visited[i]=false;
                minCost[i]=INT_MAX;
            } 
        }

        int findCost(int startNode){
            minCost[startNode]=0;
            for(int i=0 ; i< N ; i++){
                for(int j =0 ; j<N ; j++){
                    if(array_connections[i][j]!=0 and visited[i]==false){
                        int temp= minCost[i]+array_connections[i][j];
                        if(minCost[j]>temp){
                            minCost[j]=temp;
                        }
                    }
                }
                visited[i]=true;
            }
            int count=0;
            do{
                count=0;
                for(int i=0 ; i<N ; i++){
                    for(int j=0 ; j<N ; j++){
                        if(array_connections[i][j]!=0){
                            if(minCost[i]>minCost[j]+array_connections[i][j]){
                                minCost[i]=minCost[j]+array_connections[i][j];
                                count++;
                            }                            
                        }
                    }
                }
            } while(count>0);
            
            print(minCost,startNode);
            return 0;
        }

        inline void print(int *arr,int startNode){
            cout<< "Minimum cost to reach each node (in serial order) from "<<startNode<<" is : " <<endl ;
            for(int i=0 ;i<N ; i++){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
                     
    int arr[N][N]={ {0,4,5,0,0},
                    {4,0,9,3,0},
                    {5,9,0,0,8},
                    {0,3,0,0,2},
                    {0,0,8,2,0} };

    Dijkstra obj(arr);
    obj.findCost(0);

    return 0;
}