/*================================================================================================================================================================================
* File Name : Clinick_ManagementSystem_MainProgram.c
* Created on: Jan 3, 2020
* Author: Nour Emam Adly 
* Assignment: Clinic Management System Project 
* Description: 
*=================================================================================================================================================================================*/
 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clinic_ManagementSystem_Interface.h"
#include "Clinic_ManagementSystem_Private.h"




/*-----------------------------------------------------------------------------------------------------------------------
 *            (1) Function Description : Function To Start Your Program
 *                                                    And
 *                                   To Choose The Required Mode(Admin or User Mode)
 * ----------------------------------------------------------------------------------------------------------------------*/

void SelectMode_Func(void)
{
	 int Mode;
   /* Welcoming Message Then Choose The Required Mode */
	    printf("                   ************ Welcome To Our Clinic Management System Program ************   \n\n");
	    printf("-> Please Choose Which mode you want <- \n");
	    printf("-----------------------------------------\n");
	    printf("1- Admin Mode \n2- User Mode\n");
	    printf("Please Enter The Number That Represent Your Mode Choice : ");

   /* Scanning For The Required Mode */
	    scanf("%d",&Mode);
	    printf("\n");

  /*Switching On The Required Mode And Call The Required Mode Function*/
	 switch(Mode){
	    case 1 :
	   /* Call The Admin Mode Function */
	    	Admin_Mode();
	        break;
	    case 2 :
	   /* Call The User Mode Function */
	    	User_Mode();
	        break;
	    default :
	   /* Print A Message For The User To Re Enter The Right Choice */
	    	printf("                     ********* Invalid Choice ********* \n");
	    	printf("             ********* Please Choose The Right Mode ********* \n");

	    }

}





/*-----------------------------------------------------------------------------------------------------------------------
 *           (2) Function Description : Admin Mode Function To Check For The Admin Password
 *                                                         And
 *                                           To Call The Admin Choice Function
 * ----------------------------------------------------------------------------------------------------------------------*/

void Admin_Mode(void){
	int Pass;
	int Count=0;
	printf("\nPlease Enter The Password=");
	scanf("%d",&Pass);
/* Check Admin Password ,Admin Have 3 Trials To Enter The Right Password After That The system Will Be Blocked */
for(int i=0;i<2;i++)
{
	if(Pass==PASSWORD)
	{
		printf("                                ********** Successful Login ********** \n");
		printf("                                ********** Admin Mode Window ********** \n");
		break;
	}


	else
	{
	     printf("Please Renter The Right Password= ");
	     scanf("%d",&Pass);
	     Count++;
	}

}
if (Count<2)
{
/*As The Admin Entered The Right Password Call The Admin Choice Function */
	Admin_ChoiceFunc();
}
else
{
/* As The Admin Entered Wrong Password For 3 Times The System Blocked  */
	printf("System Blocked");
}
}


/*-----------------------------------------------------------------------------------------------------------------------
 *   (3) Function Description : Admin Choice Function To Call The Required Admin Function From This List:
 *                                1-Add New Patient Record
 *                                2-Edit Patient Records
 *                                3-Reserve A Slot With A doctor
 *                                4-Cancel Reservation
 *                                5-Return Back To The Select Mode Page
 * ----------------------------------------------------------------------------------------------------------------------*/

void Admin_ChoiceFunc(void){

	int Choice_Num;


	while(1){
/* Print The Admin Page Choices */
		printf("1-Add New Patient Record \n");
		printf("2-Edit Patient Records \n");
		printf("3-Reserve A Slot With A doctor \n");
		printf("4-Cancel Reservation \n");
		printf("5-Return to the Select Mode Page \n");

/* Scanning The Admin Required Choice */
	printf("Please Enter The Number That Represent Your Choice From This List :");
		scanf("%d",&Choice_Num);

	switch (Choice_Num){

	  case 1:
/* Call Add New Patient Informations Function To The Clinic Database */
        AddPatient_Func();
	     break;

	  case 2:
/* Call Edit Patient Informations Function In The Clinic Database */
		  EditPatientInfo_Func();
		break;

	  case 3:
/* Call Reserve Slot With A Doctor Function For Certain Patient  */
		   ReserveSlot_Func();
	 	break;

	  case 4:
/* Call Cancel The Reservation Of Doctor Function For Certain Patient */
		  CancelReservation_Func();
	   	break;

	  case 5:
/* Call The Select Mode Again To Return Back To The Select Mode Page Again */
		  SelectMode_Func();
		  	 break;
	  default:
		printf("                     ********* Invalid Choice ********* \n");
		printf("             ********* Please Choose the right action ********* \n");
		break;
	}


	}


}




/*-----------------------------------------------------------------------------------------------------------------------
 *      (4) Function Description : Function To Add New Patient Informations In The Clinic Database
 * ----------------------------------------------------------------------------------------------------------------------*/
void AddPatient_Func(void){
    if(availableSlots){
/* Create New Node Containing The New Patient Informations */
    	struct Patient_Node *link = (struct Patient_Node*) malloc(sizeof(struct Patient_Node));

/* Scanning The Patient Informations From The Admin */
printf("                ********* Please Enter The Patient Informations ********* \n");
        printf("\n");
        printf("Patient Name : ");
        scanf("%s",&link->name);
        printf("\n");
        printf("Patient Age : ");
        scanf("%d",&link->age);
        printf("\n");
        printf("Patient Gender : ");
        scanf("%s",&link->gender);
        printf("\n");
        printf("Patient ID : ");
        scanf("%d",&link->id);
        printf("\n");

 /* Set The Intitial Value Of The Next Of The New Link Node To NULL */
        link->next = NULL;
 /* Check If There Is Already Node Exist Or Not*/
        if(head == NULL){
 /* As The Head Pointer Still NULL And There Is No Linked List So Create A New Node In The Linked List */
            head = link;
        }
        else{
            struct Patient_Node *Ptr1,*Ptr2;
            Ptr1 = Ptr2 = head;
  /*Check If the Input ID Is Already Exist Or Not And If it Exists Re Enter A New ID */
            while(Ptr2 != NULL){
                if(link->id == Ptr2->id){
                    printf("\nThis ID already exists.\n"
                           "Please Enter New ID : ");
                    scanf("%d",&link->id);
                    Ptr2 = head;
                }
                Ptr1 = Ptr2;
                Ptr2 = Ptr2->next;
            }
            Ptr1->next = link;
        }
    }
 /* If There Is No Availible Slots For Doctor Reservations Print A Message
  *          For The Admin That There is No Availible Slots               */
    else{
        printf("Sorry There Are No Available Slots \n");
    }

}


/*-----------------------------------------------------------------------------------------------------------------------
 *      (5) Function Description : Function To Edit The Patient Informations By Entering The Patient ID
 * ----------------------------------------------------------------------------------------------------------------------*/

void EditPatientInfo_Func(){
	/*Create A Local Pointer To Move On All The Nodes And Search
	 *    For The Right ID Of The Patient To Edit His/Her Informations */
    struct Patient_Node *Ptr1=head;
    int ID;
    int count=0;
    printf("\nPlease Enter the ID of the patient that you want to change His/Her Information : ");
    scanf("%d",&ID);
/* Search For The Patient ID That You Want To Edit His/Her Informations */
    while(Ptr1->next != NULL){
        if(ID == Ptr1->id){
 /* Once You Find The Patient ID Edit This Patient Informations By Entering His/Her Information Again */
        	count=1;
            printf("\n");
            printf("Please Enter the New Patient Name : ");
            scanf("%s",&Ptr1->name);
            printf("\n");
            printf("Please Enter the New patient age : ");
            scanf("%d",&Ptr1->age);
            printf("\n");
            printf("Please Enter the New patient gender : ");
            scanf("%s",&Ptr1->gender);
            printf("\n");
            break;
        }
        Ptr1 = Ptr1->next;
    }
 /* If You Didn't Find The Patient ID Print A message For The User To Re Enter The Right ID */
    if (count == 0){
    	printf("                                ********* Invalid ID ************ \n");
    	printf("If you still want to edit a patient info choose Edit patient Informations from the list again \n");
    	printf("-------------------------------------------------------------------------------------------------\n");

    }

}


/*-----------------------------------------------------------------------------------------------------------------------
 *            (6)  Function Description : Function To Reserve Doctor Slot For Patient Using ID
 * ----------------------------------------------------------------------------------------------------------------------*/

void ReserveSlot_Func(void){
/*Create A Local Pointer To Move On All The Patients Nodes And Check The ID Until Finding The Requred Patient Node
 *  To Reserve A Slot For The Required Patient */
    struct Patient_Node* Ptr1;
    int i, j =0;
    int ID;
    Ptr1 = head;

 /*Check if there is linked list with patients data or not */
    if(Ptr1 == NULL){
        printf("There are no patients In The Database \n");
    }
 /*If there is Database with Patients Info So Scan the ID of the Patient That Want
   *  to reserve A Slot with A Doctor                                              */
    else{
        printf("Please Enter The Patient ID That You Want To Make a Reservation : ");
        scanf("%d",&ID);
        printf("\n");
 /* Move The Ptr1 On All the Node Until You Find The Required Patient ID*/
        while(Ptr1!= NULL){
 /*If You Find The Required Patient ID Then Print All The Availible Slots Timings */
            if(ID == Ptr1->id){
                for(i=1;i<= NO_OF_SLOTS;i++,j++){
                    switch(arr[j]){
                        case 1 :
                            printf("1- From 2:00 PM To 2:30 PM \n");
                            break;

                        case 2 :
                            printf("2- From 2:30 PM To 3:00 PM \n");
                            break;

                        case 3 :
                            printf("3- From 3:00 PM To 3:30 PM \n");
                            break;

                        case 4 :
                            printf("4- From 4:00 PM To 4:30 PM \n");
                            break;

                        case 5 :
                            printf("5- From 4:30 PM To 5:00 PM \n");
                            break;
                    }
                }
 /* Choose The Slot That You Want To Reserve And Delete This Slot From The Availible Slots For The Upcoming Reservations */
                printf("Please Select The Slot That You Want To Reserve : ");
                scanf("%d",&Ptr1->slot);
                arr[Ptr1->slot-1] = 0;
                availableSlots--;
                return;
            }
            else{
                Ptr1 = Ptr1->next;
            }
        }
 /* If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf("Incorrect ID Please Re Enter The Right ID : \n");
    }
}


/*-----------------------------------------------------------------------------------------------------------------------
 *         (7) Function Description : Function To Cancel Reservation of Doctor Slot For Patient Using ID
 * ----------------------------------------------------------------------------------------------------------------------*/

void CancelReservation_Func(void){
    struct Patient_Node* Ptr1;
    int ID;
    Ptr1 = head;
/* Check If There Is Patient Informations In The Database Or Not If Not Print This Message For The Admin */
    if(Ptr1 == NULL){
        printf("There are no patients In The Database \n");
    }
/* If There Is Patient Informations In The Database Ask The Admin To Enter The ID
 *        Of The Patient That Want To Cancel A Reservation                          */
    else{
        printf("Please Enter The Patient ID That you want to Cancel The Reservation : ");
        scanf("%d",&ID);
/* Make A Loop Until You Find The Node That Contains The Same ID Of The Required Patient
 *     Then Cancel The Reservation                                                   */
        while(Ptr1!= NULL){
            if(Ptr1->id == ID){
                arr[Ptr1->slot-1] = Ptr1->slot;
                availableSlots++;
                return;
            }
            else{
 /* Set The Pointer To The Following Node To Check For The ID Till You Find */
                Ptr1 = Ptr1->next;
            }
        }
/*If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf(" Incorrect ID Please Re Enter The Right ID :\n");
    }
}

/*-----------------------------------------------------------------------------------------------------------------------
 *        (8) Function Description : User Mode Function To Call the Function that the user want :
 *                                     1-View Patient Informations
 *                                     2-View Today Reservations
 *                                     3-Return To The Select Mode Page
 * ----------------------------------------------------------------------------------------------------------------------*/

void User_Mode(void){
  	printf("                                ********** User Mode Window ********** \n");
    int ch;
    while(1){
 /* Ask The User To Enter The Required Choice */
        printf("1- View Patient Informations \n");
        printf("2- View Today Reservations \n");
        printf("3- Return To The Select Mode Page \n");
 printf("Please Enter The Number That Represent Your Choice From This List :");
        scanf("%d",&ch);

        switch(ch){
            case 1 :
 /* Call The View Patient Informations Function */
            	ViewPatientInformation_Func();
                break;

            case 2 :
 /* Call The View Reservations Function */
            	ViewPatientsReservations_Func();
                break;

            case 3 :
 /* Call The Select Mode Functions To Return Back To The Select Mode Menu */
            	SelectMode_Func();
                break;

/*If The User Enter Wrong Choice Print A message To Re Choose The Right Action*/
            default :
            	printf("                     ********* Invalid Choice ********* \n");
            	printf("             ********* Please Choose The Right Action ********* \n");
                break;
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------
 *                (9) Function Description : Function To View Patient Informations By Entering The ID
 * ----------------------------------------------------------------------------------------------------------------------*/

void ViewPatientInformation_Func(void){
/* Create A Pointer To Move On All The Patients Nodes To Print Every Patient Node Informations*/
    struct Patient_Node *Ptr1;
    int ID;
    Ptr1 = head;
    if(Ptr1 == NULL){
/* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("There are no patients.\n");
    }
    else{
        printf("Enter patient ID : ");
        scanf("%d",&ID);
 /*Make A Loop On All The Nodes And Print Every Patient Informations */
        while(Ptr1!= NULL){
            if(ID == Ptr1->id){
            	printf("Patient Name : %s",Ptr1->name);
            	printf("\n");
            	printf("Patient Gender : %s",Ptr1->gender);
            	printf("\n");
            	printf("Patient Age : %d",Ptr1->age);
            	printf("\n");
            	printf("Patient ID : %d",Ptr1->id);
            	printf("\n");
                return;
            }
            else{
                Ptr1 = Ptr1->next;
            }
        }
 /*If The User Entered Wrong ID Print A Message To Re Enter The Right ID */
        printf("Incorrect ID Please Re Enter The Right ID : \n");
    }
}


/*-----------------------------------------------------------------------------------------------------------------------
 *                          (10) Function Description : Function To View All the Reservations
 * ----------------------------------------------------------------------------------------------------------------------*/

void ViewPatientsReservations_Func(void){
/* Create A Pointer To Move On All The Patients Nodes To Print All The Patients Reservations  */
    struct Patient_Node *Ptr1;
    int slot;
    Ptr1 = head;
    if(Ptr1 == NULL){
/* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
    else{
/* Print All The Reservations Of All The Patients */
        printf("ID: reservation slot:\n");
        while(Ptr1!= NULL){
           switch(Ptr1->slot){
            case 1 :
               printf("%d   2:00 PM : 2:30 PM.\n",Ptr1->id);
               break;

            case 2 :
               printf("%d   2:30 PM : 3:00 PM.\n",Ptr1->id);
               break;

            case 3 :
               printf("%d   3:00 PM : 3:30 PM.\n",Ptr1->id);
               break;

            case 4 :
               printf("%d   4:00 PM : 4:30 PM.\n",Ptr1->id);
               break;

            case 5 :
               printf("%d   4:30 PM : 5:00 PM.\n",Ptr1->id);
               break;

            default :
                break;
           }
           Ptr1 = Ptr1->next;
        }
    }
}

int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
/* Call The Select Mode Functions */
	SelectMode_Func();


return 0;
}





