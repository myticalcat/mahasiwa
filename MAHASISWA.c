#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*isinya fungsi & var*/

int jumlahMhs=0;
void menu();
void entrydata();
void displaydata();
void start();
void editdata();
typedef char string[100];

typedef struct {
	string nama;
	string nrp;
	double nilaiEts;
	double nilaiEas;
	double rata;
	struct node *next;	
}node;

int iglo=0;

node *root=NULL;

int main (){
	start();
	char option;
	while (1){
	system ("cls");
	menu();	
	printf("\nmasukan pilihan anda: ");
	scanf(" %c",&option);
	switch(option){
		case '1': 
			system ("cls");
			entrydata();
			break;
		case'2':
			system ("cls");
			displaydata();
			break;
		case'0':
			return 0;
		default:
			system ("cls");
            printf("Karakter anda tidak diketahui");
            break;
		}
	}
}

void menu(){
	printf("---------------------------\n");
	printf("           MENU            ");
	printf("\n---------------------------\n");
	printf("[1]Masukan Data Mahasiswa\n");
	printf("[2]Tampilkan Data Mahasiswa\n");
	printf("[0]Keluar\n");
	printf("---------------------------");
}

void entrydata(){
	/*backup array*/{
//	int jum;
//	printf("Masukan jumlah mahasiswa yang ingin di entry:\n");
//	scanf("%d", &jum);
//	jumlahMhs += jum;
////	printf("[%d][%d]",jumlahMhs,iglo);
//	for(iglo;iglo<jumlahMhs;iglo++){		
//		printf("----------------------------------\n");
//		printf("Masukan nama:");
//		scanf(" %[^\n]s ", &mahasiswa[iglo].nama);
//		printf("Masukan nrp:");
//		scanf(" %[^\n]s ", &mahasiswa[iglo].nrp);
//		printf("Masukan nilai ETS:");
//		scanf("%lf", &mahasiswa[iglo].nilaiEas);
//		printf("Masukan nilai EAS:");
//		scanf("%lf", &mahasiswa[iglo].nilaiEts);
//		mahasiswa[iglo].rata = (mahasiswa[iglo].nilaiEas+mahasiswa[iglo].nilaiEts)/2;
//	}
	}
	
	int jum,scancheck=0;
	FILE *infilep, *outfilep, *infilenama, *infileUni;
	node *temp;
	printf("Masukan jumlah mahasiswa yang ingin di entry:\n");
	scanf("%d", &jum);
	jumlahMhs = jum + iglo;
	string namaFile;
	infilenama=fopen("displayData.txt", "a");
	infileUni=fopen("dataUni.txt", "a");
	outfilep=fopen("iglo.txt", "w");
	
//	printf("[%d][%d]",jumlahMhs,iglo);
	
	for(iglo;iglo<jumlahMhs;iglo++){
		system ("cls");
		printf("masukan data siswa ke-%d\n",iglo+1);
		temp=(node *)malloc (sizeof (node));
		printf ("Masukkan Nama:"); 
		scanf (" %[^\n]s ", &temp->nama);
		
		itoa(iglo+1,namaFile,10);
		
		infilep=fopen(namaFile, "w");
		
		fprintf(infilep,"Nama:%s\n",temp->nama);
		fprintf(infileUni,"Nama:%s\n",temp->nama);
		fprintf(infilenama,"[%d]%s\n",iglo+1,temp->nama);
		
		printf ("Masukkan NRP:"); 
		scanf (" %[^\n]s ", &temp->nrp);
		fprintf(infilep,"NRP:%s\n",temp->nrp);
		fprintf(infileUni,"NRP:%s\n",temp->nrp);
		

		printf ("Masukkan Nilai ETS:"); 
		scanf ("%lf", &temp->nilaiEts);
		fprintf(infilep,"Nilai ETS:%.2lf\n",temp->nilaiEts);
		fprintf(infileUni,"Nilai ETS:%.2lf\n",temp->nilaiEts);
		
		printf ("Masukkan Nilai EAS:"); 
		scanf ("%lf", &temp->nilaiEas);
		fprintf(infilep,"Nilai EAS:%.2lf\n",temp->nilaiEas);
		fprintf(infileUni,"Nilai EAS:%.2lf\n",temp->nilaiEas);
		
		fprintf(infilep,"Nilai Rata-rata:%.2lf\n", (temp->nilaiEts+temp->nilaiEas)/2);
		fprintf(infileUni,"Nilai Rata-rata:%.2lf\n-----------------------------------------\n", (temp->nilaiEts+temp->nilaiEas)/2);
		
		temp->next=NULL;
		
		if (root==NULL){
			root=temp;
		}
		else {
			node *temp1;
			temp1=root;
			while (temp1->next!=NULL){
				temp1=temp1->next;
			}
			temp1->next=temp;
		}
		fclose(infilep);
	}
	fclose(infilenama);
	fclose(infileUni);
	fprintf(outfilep,"%d",iglo);
	fclose(outfilep);
}




void displaydata(){
	/*backup array*/
{
//	int i = 0,absen;
//	printf("---------------------------\n");
//	printf("        DATA SISWA        ");
//	printf("\n---------------------------\n");
//	for (i=0;i<jumlahMhs;i++){
//		printf("[%d]%s\n",i+1,mahasiswa[i].nama);
//	}
//	printf("[0]Keluar\n");
//	while (1){
//		printf("---------------------------\n");
//		printf("Masukan nomor mahasiswa : ");
//		scanf("%d",&absen);
//		printf("%d",absen);
//		if(absen < 0 || absen > jumlahMhs){
//			printf("Nomor yang anda masukan tidak terdaftar.\n");
//			}
//		else if (absen == 0) return;
//		else{
//			printf("Nama : %s\n",mahasiswa[absen-1].nama);
//			printf("NRP : %s\n",mahasiswa[absen-1].nrp);
//			printf("Nilai ETS : %.1lf\n",mahasiswa[absen-1].nilaiEts);
//			printf("NIlai EAS : %.1lf\n",mahasiswa[absen-1].nilaiEas);
//			printf("Nilai Rata-rata : %.1lf\n",mahasiswa[absen-1].rata);
//		}	
//	}
}
	system ("cls");
	FILE *infilep, *infileUni, *infileSat;
	printf("---------------------------\n");
	printf("        DATA SISWA        ");
	printf("\n---------------------------\n");
	infilep=fopen("displayData.txt", "r");
	int status; 
	char pointer;
	string namafile,batasAtas;
	
	itoa(iglo,batasAtas,10);
	
	status=fscanf(infilep,"%c",&pointer);
	while (status!=EOF){
		printf("%c", pointer);
		status=fscanf(infilep,"%c", &pointer);
	}
	printf("[s]Semua data\n[0]Keluar\n");
	while (1){
		printf("masukan nomor siswa:");
		scanf(" %s",&namafile);
		if (strcmp(namafile,"s") == 0 || strcmp(namafile,"S") == 0 ){
			infileUni=fopen("dataUni.txt", "r");
			status=fscanf(infileUni,"%c",&pointer);
			while (status!=EOF){
				printf("%c", pointer);
				status=fscanf(infileUni,"%c", &pointer);
			}
			fclose(infileUni);
		}
		else if (*namafile == '0'){
			return;
		}
		else{
			infileSat=fopen(namafile, "r");
			status=fscanf(infileSat,"%c",&pointer);
			
			if (status!=1){
				printf("data anda tidak terdaftar\n");
			}
			else{
				printf("-----------------------------------------\n");
				while (status!=EOF){
					printf("%c", pointer);
					status=fscanf(infileSat,"%c", &pointer);
				}
				printf("-----------------------------------------\n");
			}
			fclose(infileSat);
		}
	}
}

void start(){
	FILE * startP;
	int status;
	startP=fopen("iglo.txt", "r");
	status=fscanf(startP,"%d",&iglo);
	if (status == 0){
		iglo=0;
	}
	else{
		while (status!=EOF){
			status=fscanf(startP,"%d", &iglo);
		}
	}
	fclose(startP);
}
