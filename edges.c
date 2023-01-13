#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vert_ vert;
typedef struct edge_ edge;

void new_vert(vert * arr_vert1);
void delete_vert (vert ** arr);
void delete (vert ** arr, int input);

typedef struct edge_
{
    int weight;
    vert * dest_vert;
    edge * next;
} edge;

typedef struct vert_
{
    int value;
    edge * next_edge;
    vert * nextV;    
} vert;

void check(vert * arr){
    vert * head = arr;
    int i = 0;
    while(arr != NULL)
    {
        printf ("arr[%d]:%d\n",i,arr->value);
        edge** print_edge = NULL;
        print_edge = &(arr->next_edge);
        // if (arr->next_edge != NULL){
            // printf("arr->next_edge.weight %d\n", arr->next_edge->weight);
            while (*print_edge != NULL)
            {
                printf("weight = %d, dest = %d\n", (*print_edge)->weight, ((*print_edge)->dest_vert)->value);
                print_edge = &(*print_edge)->next;
                
            } 
            i++;
        // }
        arr = arr->nextV;
    }
    arr = head;

}

char new_graph (vert ** head_of_vert){
    if (*head_of_vert != NULL)
    {
        vert * head = *head_of_vert;
        while(head != NULL){
            delete(&head,head->value);
        }
    }
    
    int num_of_vert = 0;
    scanf("%d", &num_of_vert);
    // printf ("input = %d\n", num_of_vert);
    vert ** last_vert = NULL;
    vert * array_of_vert = *head_of_vert;
    for (int i = 0; i< num_of_vert; i++){
        if((array_of_vert = (vert*) malloc(sizeof (vert))) == NULL){
        printf ("Not enough memory1, exit program\n");
        exit(-1);
        }
        if (i == 0)
        {
            *head_of_vert = array_of_vert;
            last_vert = &array_of_vert; 
        }
        array_of_vert->next_edge = NULL;
        array_of_vert->value = i;
        array_of_vert->nextV = NULL;
        *last_vert = array_of_vert;
        last_vert = &array_of_vert->nextV;
    }
    array_of_vert = *head_of_vert;
   
    int input_from_user = 0;
    int num_from_user = 0;
    int vert_from_user = 0;
    char n = '0';

    while (scanf("%d" ,&input_from_user) != EOF){
        scanf("%c", &n);
        if (n!= 'n'){
            return (n);
        }

        scanf ("%d", &vert_from_user);
        // printf ("input = %d\n", vert_from_user);
        edge** last_edge = NULL;
        while(array_of_vert != NULL){
            
            if(array_of_vert->value  == vert_from_user){
                break;
            }
            else{
                array_of_vert = array_of_vert->nextV;
            }
        }
        last_edge = &(array_of_vert->next_edge); 
        num_from_user = scanf("%d", &input_from_user);
        // printf ("input = %d\n", input_from_user);
        
        while (num_from_user != EOF  && num_from_user != 0){
            
            edge * new_edge = NULL;
            if((new_edge = (edge*) malloc (sizeof(edge) )) == NULL)
            {
                printf ("Not enough memory2, exit program\n");
                exit(-1);
            }

            *last_edge = new_edge;
            (*last_edge)->dest_vert = NULL;
            (*last_edge)->next = NULL;
            (*last_edge)->weight = 0;
            vert * search_dest = *head_of_vert;

            while (search_dest != NULL){
                
                if (search_dest->value == input_from_user){
                    break;
                }
                else{
                    search_dest = search_dest->nextV;
                }
            }
            (*last_edge)->dest_vert = (search_dest);
            scanf("%d", &input_from_user);
            // printf ("input = %d\n", input_from_user);
            (*last_edge)->weight = input_from_user;
            last_edge = &((*last_edge)->next);
            num_from_user = scanf("%d", &input_from_user);
            // printf ("input = %d\n", input_from_user);
        }
        array_of_vert = *head_of_vert;
        

    } 
    return (n);   

}

void new_vert(vert * arr_vert1){
    int input_from_user = 0;
    int flag1 = 1;
    int flag2 = 1;
    
    scanf ("%d", &input_from_user);
    vert * arr_vert = arr_vert1;
    vert * prev = arr_vert;
    while(arr_vert != NULL){
        if (arr_vert->value == input_from_user){
            flag1 = 0;
            edge * delet_next_edge1 = arr_vert->next_edge;
            edge * delet_next_edge2 = NULL; 
            while (delet_next_edge1 !=NULL)
            {
                delet_next_edge2 = delet_next_edge1->next;
                free (delet_next_edge1);
                delet_next_edge1 = delet_next_edge2;
                if (delet_next_edge1 !=NULL){   
                    delet_next_edge2 = delet_next_edge2->next;
                }
            }
            arr_vert->next_edge = NULL;
            break;
        }
        else{
            arr_vert = arr_vert->nextV;
        }
        if (!flag2 && prev != NULL){

            prev = prev->nextV;    
        }
        flag2 = 0;
    }
    
    if (flag1){
        arr_vert = prev;
        vert * new_vert = NULL;
        
        if((new_vert = (vert*) malloc (sizeof(vert) )) == NULL)
        {
            printf ("Not enough memory2, exit program\n");
            exit(-1);
        }

        new_vert->value = input_from_user ;
        new_vert->next_edge = NULL;
        new_vert->nextV = NULL;
        arr_vert->nextV = new_vert;
        arr_vert = arr_vert->nextV;
    }

    edge** last_edge = NULL;
    last_edge = &(arr_vert->next_edge); 


    //we got from user the dest of edge
    int num_from_user = scanf("%d", &input_from_user);
    
    while (num_from_user != EOF  && num_from_user != 0){  
        edge * new_edge = NULL;
        if((new_edge = (edge*) malloc (sizeof(edge) )) == NULL)
        {
            printf ("Not enough memory2, exit program\n");
            exit(-1);
        }
        *last_edge = new_edge;
        (*last_edge)->dest_vert = NULL;
        (*last_edge)->next = NULL;
        (*last_edge)->weight = 0;

        vert * search_dest = arr_vert1;
        while (search_dest != NULL){
            
            if (search_dest->value == input_from_user){
                break;
            }
            else{
                search_dest = search_dest->nextV;
            }
        }
        (*last_edge)->dest_vert = search_dest;

        //the weight of the edge
        scanf("%d", &input_from_user);
        (*last_edge)->weight = input_from_user;
        last_edge = &((*last_edge)->next);

        //input could be 'n' or int anyaway it goes to the while loop
        num_from_user = scanf("%d", &input_from_user);

    }
    arr_vert = arr_vert1;
}

//what we want to delete
void delete_vert (vert ** arr){
    int input = 0;
    scanf ("%d", &input);
    delete (arr, input);
}

void delete (vert ** arr, int input){

    //3 pointers to the verts
    vert * vert1 = *arr;
    vert * vert2 = *arr;
    vert * vert3 = *arr;

    //2 pointers to the edges
    edge ** edge1 = &((*arr)->next_edge);
    edge * edge2 = (*arr)->next_edge;

    //flags
    int flag_edge = 1;
    int flag_vert = 1;
    int flag_found = 1;
    int flag_first = 0;
    
    //if the delete is for the first vert
    if (vert2->value == input){
        flag_first = 1;
    }
    
    while (vert3 != NULL){
        if (vert3->value != input){
            while (edge2 != NULL)
            {
                if (!flag_edge){
                    edge1 = &((*edge1)->next); 
                       
                }
                flag_edge = 0;
                
                if (edge2->dest_vert->value == input){
                    edge2 = edge2->next;
                    free((*edge1));
                    (*edge1) = (edge2);
                    
                }
                else{
                    edge2 = edge2->next;
                }
            }

            //if we found the prev time the vert so increase only vert 3. also, in the first time increase only vert2 & vert3
            if(flag_found){
                if(!flag_vert){
                    vert1 = vert1->nextV;
                }
                vert2 = vert2->nextV;
            }
            vert3 = vert3->nextV;
            flag_vert = 0;
            if (vert3 != NULL){
                edge1 = &(vert3->next_edge);
                edge2 = vert3->next_edge;
            }
            flag_edge = 1;   
        }

        //if we found this time the vert
        else{
            flag_found = 0;
            vert3 = vert3->nextV;
            flag_vert = 0;
            if (vert3 != NULL){
                edge1 = &(vert3->next_edge);
                edge2 = vert3->next_edge;
            }
            flag_edge = 1;
        }
    }

    //if the delete is for the first vert
    if(flag_first) {
        *arr = (*arr)->nextV;
    }
    edge1 = &(vert2->next_edge);
    edge2 = NULL; 
    while ((*edge1) !=NULL)
    {
        edge2 = (*edge1)->next;
        free ((*edge1));
        (*edge1) = edge2;
        if ((*edge1) !=NULL){   
            edge2 = edge2->next;
        }
    }
    vert2->next_edge = NULL;

    vert3 = vert2->nextV;
    vert2->nextV = NULL;
    free(vert2);
    vert1->nextV = vert3;

}


int main(){
    vert * head = NULL;
    char n = '0';
    int scan = scanf("%c", &n);
    int flag = 1;
    int flag_break = 1;
    while (scan != 0 && flag_break){
        switch(n){
            case 'A':
                n = new_graph(&head);
                printf("A:\n");
                check (head);
                printf ("\n");
                flag = 0;
                break;
            case 'B':
                new_vert(head);
                printf("B:\n");
                check (head);
                printf ("\n");
                scan = 0;
                break;
            case 'D':
                delete_vert(&head);
                printf("D:\n");
                check (head);
                printf ("\n");
                scan = 0;
                break;
            default:
                flag_break = 0;
        }
        if (flag){
            scan = scanf("%c", &n);
        }
        flag = 1;
    }
    return 0;
}
