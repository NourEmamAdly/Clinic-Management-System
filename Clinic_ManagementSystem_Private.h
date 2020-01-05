/*================================================================================================================================================================================
* File Name : Clinic_ManagementSystem_Private.h
* Created on: Jan 3, 2020
* Author: Nour Emam Adly 
* Assignment: Clinic Management System Project 
* Description: 
*=================================================================================================================================================================================*/
 
                                /* Defining The Admin Password */
#define PASSWORD 123
                                /* Defining The Availible No Of Slots */
#define NO_OF_SLOTS 5


                                /* Global Variables Decalaration */

int availableSlots =5;    // total number of available slots
int arr[5] = {1,2,3,4,5};  //array of available slots


                                  /* Patient Node */
struct Patient_Node
{
   char name[30];
   char gender[30];
   int id;
   int age;
   int slot;
   struct Patient_Node *next;
};

                                 /* Creating Head Pointer */
struct Patient_Node *head = NULL;
