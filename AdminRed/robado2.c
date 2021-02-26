/*header*/
#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
/*macro*/
#define NUM_THREADS     9
/*I have defined the structure here to pass the multiple arguments 
when creating threads*/
/*structure declaration*/
struct thread_data
{
    int  element1[3];//passing the element of one matrix
    int  element2[3];//passing the element of other matrix
    int sum;//storing the result of multiplication
}thread_data_array[NUM_THREADS];
/**
 * @brief finds matrix multiplication function
 * param [in] : accepts the thread arguments
 *
 * @return void pointer
 */
void *multiplication(void *threadarg)
{
    int i;
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;/*type cast the 
void pointer to the struct thread*/
    //pointer
    my_data->sum=0;
    for(i=0;i<3;i++){/*multiply and add each element
of 1st matrix to 2nd matrix*/
        my_data->sum=my_data->sum
            +((my_data->element1[i])*(my_data->element2[i]));
    }
}
/*main*/
int main (int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int t;
    int matrix_b[3][3]={{156,223,345},{456,5678,656},{712,811,922}};
//to store the matrix
    int matrix_a[3][3]={{123,278,335},{437,547,656},{734,832,944}};
    int ans[9];
    int i,j,count,z,k,l,q;
    t=i=j=z=count=k=q=l=0;
/*
suppose the matrices are
1 2 3       1 2 3
4 5 6       1 2 3
7 8 9       1 2 3
so to perform the multiplication
row 1 2 3 will be multiplied too column 
111 222 333 respectively.
so 123 shold be stored in 3 spreate threads 
and 111 222 333 should be stored in 3 seprate threads
123 111 should be in common thread
123 222 should be in common thread
123 333 should be in common thread
in this way below logic i have
writtten.
It is hard to understand at first glance..
so enjoy!!!!!!
*/
    while(z<3){
            for(count=0;count<3;count++){/*store the each row of
first matrix 3 times in 3 seprate threads*/
                for(j=0;j<3;j++)
                    thread_data_array[t].element1[j] 
                        = matrix_a[i][j];
                t++;
            }
/*store the each column of the second matrix in the spreate threads*/
            for(k=0;k<3;k++){
                for(l=0;l<3;l++)
                    thread_data_array[q].element2[l] 
                        = matrix_b[l][k];
                q++;
            }
            i++;
            z++;
    }
/*we have total 9 element in resultant matrix,so to create it we should
create 9 threads*/
    for(t=0; t<NUM_THREADS; t++){
        rc =pthread_create (&threads[t], NULL, multiplication,
                (void *) &thread_data_array[t]);
/*we are passing the function pointer and

the pointer to structure as the argument,since we want to pass multiple argumen
ts we                         are passing the structure poi
nter as the arguments.*/
        if (rc){//if rc is not 0,error is there
            printf("ERROR; return code from () is %d\n", rc);
            exit(-1);
        }
    }
/*
NAME         

       pthread_join - join with a terminated thread

SYNOPSIS         

       #include <pthread.h>

       int pthread_join(pthread_t thread_here, void **retval);

       Compile and link with -pthread.

DESCRIPTION         

   The pthread_join() function waits for the thread specified by thread_here
    to terminate.  If that thread has already terminated, then
    pthread_join() returns immediately.  The thread specified by thread
    must be joinable.
*/
    for (i = 0; i < 9; i++)/*to wait for all the threads to complete*/
            pthread_join(threads[i], NULL);
    printf("%d %d %d\n",thread_data_array[0].sum,thread_data_array[1].sum,thread_data_array[2].sum);
    printf("%d %d %d\n",thread_data_array[3].sum,thread_data_array[4].sum,thread_data_array[5].sum);
    printf("%d %d %d\n",thread_data_array[6].sum,thread_data_array[7].sum,thread_data_array[8].sum);
}