/*================================================================================================================================================================================
* File Name : Clinic_ManagementSystem_Interface.h
* Created on: Jan 3, 2020
* Author: Nour Emam Adly 
* Assignment: Clinic Management System Project 
* Description: Functions Prototypes
*=================================================================================================================================================================================*/
 
#ifndef CLINIC_MANAGEMENTSYSTEM_INTERFACE_H_
#define CLINIC_MANAGEMENTSYSTEM_INTERFACE_H_


                                 /* Select Mode Function */

void SelectMode_Func(void);

                                 /* Admin Mode Functions */

void Admin_Mode(void);
void Admin_ChoiceFunc(void);
void AddPatient_Func(void);
void EditPatientInfo_Func(void);
void ReserveSlot_Func(void);
void CancelReservation_Func(void);

                                 /* User Mode Functions */
void User_Mode(void);
void ViewPatientInformation_Func(void);
void ViewPatientsReservations_Func (void);















#endif /* CLINIC_MANAGEMENTSYSTEM_INTERFACE_H_ */
