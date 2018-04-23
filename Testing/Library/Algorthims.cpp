#include "Algorthims.h"



Algorthims::Algorthims()
{

	for (int i = 0; i < popCount; i++)
	{
		Solution.push_back(new Gene(0,3));
	}
}

void Algorthims::PopulationCreator()
{
	

	for (int i = 0; i < popCount; i++)
	{
		Gene* geneToAdd;
			
		geneToAdd = new Gene(rand() % 3, 0);
		geneToAdd->CalcFitness(Solution.at(i));
		Population.push_back(geneToAdd);
	}

}








Algorthims::~Algorthims()
{
}
