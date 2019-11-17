#include "cal.h"
void calc_prg_1(char *host)
{
CLIENT *clnt;
int *result_1;
variable calc_1_arg;
clnt = clnt_create (host, calc_prg, calc_version, "udp");
if (clnt == NULL) {
clnt_pcreateerror (host); exit (1);
}

printf("\n1 addition \n2.multiplication \n3.subtraction \n4.division\n5.remainder \n6.is first number prime \n7.is both numbers odd or even\nenter choice :");

scanf("%d",&calc_1_arg.choice);
printf("enter values");
int validate = scanf("%d %d",&calc_1_arg.x,&calc_1_arg.y);
if(validate !=2){
   printf("Arguments are not of valid type");
exit(0);
}

result_1 = calc_1(&calc_1_arg, clnt);

if (result_1 == (int *) NULL) {
clnt_perror (clnt, "call failed");
}
if(calc_1_arg.choice!=6 && calc_1_arg.choice!=7)
printf("Your result is %d\n",*result_1);
else if((calc_1_arg.choice==6 ||calc_1_arg.choice==7) && *result_1==1)
printf("\nYES\n");
else
printf("\nNO\n");
clnt_destroy (clnt);
}
int main (int argc, char *argv[])
{
char *host;
if (argc < 2) {
printf ("usage: %s server_host\n", argv[0]);
exit (1);
}
host = argv[1];
calc_prg_1 (host);
exit (0);
}
