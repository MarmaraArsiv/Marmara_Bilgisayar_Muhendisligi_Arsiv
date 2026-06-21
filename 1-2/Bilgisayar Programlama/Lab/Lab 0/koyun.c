#include <stdio.h>
#include <stdlib.h>
void kafa(int x);
void govde(int x);

int degisken;
int main(int argc, char *argv[]) {
	printf("Bir sayi giriniz:");
	scanf("%d",&degisken );
	if(degisken%2 == 1){
		degisken++;
	}
	kafa(degisken);
	govde(degisken);

	bacaklar(degisken);

	return 0;
}




void kafa(int x){
    int boy = x / 2;
	int z,y;
    if(boy < 3)
        boy = 3;

    for(z = 0; z < boy; z++){
        for(y = 0; y < boy; y++){

            if(z == 0 || z == boy-1 || y == 0 || y == boy-1){
                printf("* ");
            }
            else{
                printf("  ");
            }

        }
        printf("\n");
    }
}


void govde(int x){
int z,y,u;
for(z=0;z<x;z++){
	for(u=0;u<(x/2);u++){
		printf(" ");
	}
	for(y=0;y<x;y++){
		printf("* ");
	}
	printf("\n");
}
	
}
void bacaklar(int x){
    int z, u;
    
    float kisa = 2*((x -4 )/4); 
    float uzun = 2*(x -4 )/2;       

    for(z = 0; z < x; z++){
		
		
		for(u=0;u<(x/2);u++){
		
		printf(" ");
		
		}
		
		
        printf("*");

        for(u = 0; u < kisa; u++)
            printf(" ");
        printf("*");

        for(u = 0; u < uzun; u++)
            printf(" ");
        printf("*");

        for(u = 0; u < kisa; u++)
            printf(" ");
        printf("*\n");
    }
}


