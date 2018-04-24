#include "Algorthims.h"
#include <random>
#include <time.h>
#include <iostream>

Algorthims::Algorthims()
{
	DNASolution = "cupcakes are cute and evil and squishy";
	srand(time(NULL));

	for (int i = 0; i < Pop.Members.size(); i++)
	{
		Pop.Members.at(i).DNA.resize(DNASolution.size());

		for (int j = 0; j < DNASolution.size(); j++)
		{
			Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
		}
		Pop.Members.at(i).Fitness = 0;
	}

	generations = 0;
	SolutionFound = false;
}

Algorthims::Algorthims(std::string Solution)
{
	DNASolution = Solution;
	srand(time(NULL));

	for (int i = 0; i < Pop.Members.size(); i++)
	{
		Pop.Members.at(i).DNA.resize(DNASolution.size());

		for (int j = 0; j < DNASolution.size(); j++)
		{
			Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
		}
		Pop.Members.at(i).Fitness = 0;
	}

	generations = 0;
	SolutionFound = false;
}

void Algorthims::Setup()
{
	srand(time(NULL));

	for (int i = 0; i < Pop.Members.size(); i++)
	{
		Pop.Members.at(i).DNA.resize(DNASolution.size());

		for (int j = 0; j < DNASolution.size(); j++)
		{
			Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
		}
		Pop.Members.at(i).Fitness = 0;
	}
	
	generations = 0;
	SolutionFound = false;
}

void Algorthims::SetString(std::string string)
{
	DNASolution = string;

	for (int i = 0; i < Pop.Members.size(); i++)
	{
		Pop.Members.at(i).DNA.resize(DNASolution.size());

		for (int j = 0; j < DNASolution.size(); j++)
		{
			Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
		}
		Pop.Members.at(i).Fitness = 0;
	}

	generations = 0;
	SolutionFound = false;
}

void Algorthims::PopulationCreator()
{


	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 2); // guaranteed unbiased

	

	for (int i = 0; i < popCount; i++)
	{
		Gene* geneToAdd;
		auto random_integer = uni(rng);	
		geneToAdd = new Gene(random_integer, 0);
		geneToAdd->CalcFitness(Solution.at(i));
		Population.push_back(geneToAdd);
	}

}

void Algorthims::CalcFitness()
{
	int loopThoughItemIndex = Solution.size() - 1;

	for (int i = 0; i <= loopThoughItemIndex; i++)
	{
		if (Population.at(i)->Value == Solution.at(i)->Value)
		{
			currentFitness++;
			Population.at(i)->Fitness = 1;
		}
	}

}

void Algorthims::ParentSelection()
{
	// First, sort out the population from highest to lowest in terms of fitness
	std::sort(Pop.Members.begin(), Pop.Members.end(), [](Member const &a, Member const &b) {return a.Fitness > b.Fitness; });

	// Then, make a vector of Genes that are going to be the parents.
	Parents = std::vector<Member>{ Pop.Members.at(0),Pop.Members.at(1) };

	// Gene permutation and mating
	for (int i = 0; i < Pop.Members.size(); i++)
	{
		for (int j = 0; j < Pop.Members.at(i).DNA.size(); j++)
		{
			int TempSelection = rand() % Parents.size();
			Pop.Members.at(i).DNA.at(j) = Parents.at(TempSelection).DNA.at(j);


			// random mutation rate
			if (rand() % 1000 < MutationRate)
			{
				Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
			}

		}
	}

}

void Algorthims::FindSolution()
{

	// While the solution was not found
	while (!SolutionFound)
	{
		
		// increment the generation ticks.
		generations++;

		//clear out the fitness, then reevaluate.
		for (int i = 0; i < Pop.Members.size(); i++)
		{
			Pop.Members.at(i).Fitness = 0;

			for (int j = 0; j < Pop.Members.at(i).DNA.size(); j++)
			{
				if (Pop.Members.at(i).DNA.at(j) == DNASolution.at(j))
				{
					Pop.Members.at(i).Fitness += 10;
				}
				if (Pop.Members.at(i).Fitness == DNASolution.size() * 10)
				{
					SolutionFound = true;
				}
			}
		}

		ParentSelection();
		system("cls");
		ResultGenerations = generations;
		ResultFitness = Parents.at(0).Fitness;
		ResultString = Parents.at(0).DNA.c_str();

		std::cout << "Generation : " << generations << " Highest Fitness : " << Parents.at(0).Fitness << std::endl << "With Sequence : " << Parents.at(0).DNA.c_str() << std::endl;
		
	}
	std::cout << "Generation " << generations << " Evolved to the full sequence. " << std::endl;
	

}








Algorthims::~Algorthims()
{
}
