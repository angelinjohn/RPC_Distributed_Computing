#include<stdio.h> 
 
int main() 
{  
 // Number of events; 
 int e; 
 printf("\n enter the no of events in p1, p2 and p3\n"); 
 scanf("%d",&e); 
  
 int size = e+1; 
 // Three processes P1, P2 and P3. 
 int p1[size],p2[size],p3[size]; 
 // Index. 
 int i; 
 // P1 Message sent. 
 int m1; 
 // Message receive from P1 at P2. 
 int m21; 
 // A Message receive from P3 at P2. 
 int m23; 
 // Message event at P3. 
 int m3; 
 // Lamport clock value to increase after each event. 
 int d = 3, startingClock = 1; 
 
 printf("\n enter the event of p1 which will send msg to P2\n"); 
 scanf("%d",&m1); 
  
 printf("\n enter the event of p2 which will receive the msg from p1\n"); 
 scanf("%d",&m21); 
  
 printf("\n enter the event of p3 which will send msg to P2\n"); 
 scanf("%d",&m3); 
  
 printf("\n enter the event of p2 which will receive the msg from p3\n"); 
 scanf("%d",&m23); 
  
 p1[0]=startingClock; 
 p2[0]=startingClock; 
 p3[0]=startingClock; 
 for(i=1;i<=e;i++) 
 { 
  // Increase clock value for process P1 and P3, as both can only send message. 
  p1[i]=p1[i-1]+d; 
  p3[i]=p3[i-1]+d; 
   
  // Check whether the current event is a message receive event from Process P1 
  // at P2 and whether the message sent event at P1 has higher clock value. 
  if(i==m21 && p1[m1]>p2[i-1]) { 
   // Update clock value at message receive event at P2. 
   p2[i]=p1[m1]+d; 
    
  } 
  // Check message receive event from P3 to P2 
 
  // Check the message sent at P3 has higher clock value. 
  else if(i==m23 && p3[m3]>p2[i-1]){ 
   // clock value update of message receive at P2. 
   p2[i]=p3[m3]+d;    
  } 
  else 
  { 
   // Update clock value at P2. 
   p2[i]=p2[i-1]+d; 
  } 
 } 
  
 // clock values Printing of P1. 
 printf("\nTime stamp for P1\n"); 
 for(i=1;i<=e;i++) 
 { 
  printf("%d ",p1[i]); 
 } 
  
 // clock values Printing of P2. 
 printf("\nTime stamp for P2\n"); 
 for(i=1;i<=e;i++) 
 { 
  printf("%d ",p2[i]); 
 } 
 // clock values Printing of P3. 
 printf("\nTime stamp for P3\n"); 
 for(i=1;i<=e;i++) 
 { 
  printf("%d ",p3[i]); 
 } 
 printf("\n"); 
 return 0; 
} 