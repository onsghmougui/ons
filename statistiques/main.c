#include <stdio.h>
#include <string.h>
#include "utilisateur.h"
#include "tache.h"
int main()
{
	float t;
	int f,h;
	t=TVB("utilisateur.txt");
	printf("%f",t);
	TPHF("utilisateur.txt",&f,&h);
	return 0;
}
