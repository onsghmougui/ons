#include <stdio.h>
#include <string.h>
#include "utilisateur.h"
#include "tache.h"
int main()
{
	float t;
	t=TVB("utilisateur.txt");
	printf("%f",t);
	return 0;
}
