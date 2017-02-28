#include "meshutils.h"


int BoundaryLayerTag(Options *mshopt,Mesh *Msh)
{
	
	int iVer, iTri, iTet, NbrVer, iEfr, j, i, iDis, flag=0, NbrTag=0;
	double dis = 0.0;
	
	int *Tag = (int*)malloc(sizeof(int)*(Msh->NbrVer+1));
	memset(Tag,0,sizeof(int)*(Msh->NbrVer+1));
	
	double disMax = mshopt->DisMax;
	
	
	iDis = -1;
	for (i=0; i<Msh->SolSiz; i++) {
		if ( !strcmp(Msh->SolTag[i],"Distance") ) {
			iDis = i;
			break;
		}
	}
		
	if ( iDis < 0 ) {
		printf("  ## ERROR : no distance provided in solution file.\n");
		return(0);
	}
	
	if ( Msh->Dim != 3 ) {
		printf("  ## ERROR : BL tag not available in 2D.\n");
		return(0);
	}
	
	
	for (iVer=1; iVer<=Msh->NbrVer; iVer++) {
		
		dis = Msh->Sol[iVer*Msh->SolSiz+iDis];
		
		if ( dis <= disMax )
			Tag[iVer] = 1;		
	}
	
	NbrTag=0;
	
	if ( Msh->Dim == 3 ) {
		for (iTet=1; iTet<=Msh->NbrTet; iTet++) {
			flag = 1;
			for (j=0; j<4; j++) {
				if ( Tag[Msh->Tet[iTet][j]] == 0 ) {
					flag = 0;
					break;
				}
			}
			
			if ( flag > 0 ) {
				NbrTag++;
			}
			
			Msh->Tet[iTet][4] = flag;
			
		}
	}
	
	printf(" -- Info : %d elements were tagged. Distance max to wall = %lf\n", NbrTag, disMax);

	if ( Tag )
		free(Tag);
	
	return 1;

}