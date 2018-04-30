#include "Algorthims.h"
#include <random>
#include <time.h>
#include <iostream>
#include <SFML/System.hpp>

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

void Algorthims::Start()
{
	/*sf::Thread solutionFind(&Algorthims::FindSolution);

	solutionFind.launch();*/



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
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0.0, 1.0);


	for (int i = 0; i < popCount; i++)
	{
		Gene* geneToAdd;
		auto random_double = distribution(generator);	
		geneToAdd = new Gene(random_double, 0);
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

	//DOES WORK, BUT TESTING NEW WAY OF DOING IT.
	// First, sort out the population from highest to lowest in terms of fitness
	std::sort(Pop.Members.begin(), Pop.Members.end(), [](Member const &a, Member const &b) {return a.Fitness > b.Fitness; });

	 //Then, make a vector of Genes that are going to be the parents.
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





	//// Have a sum variable for all the fitness scores of each member of the population.
	//float sumOfFitness = 0;
	//	
	//// Add each of the scores to the sum.
	//for (int i = 0; i < Pop.Members.size(); i++)
	//{
	//	sumOfFitness += Pop.Members.at(i).Fitness;
	//}

	//// Have the probability of member be calculated.
	//for (int i = 0; i < Pop.Members.size(); i++)
	//{
	//	if (Pop.Members.at(i).Fitness == 0)
	//	{
	//		Pop.Members.at(i).probablity = 0;
	//	}
	//	else
	//	{
	//		Pop.Members.at(i).probablity = Pop.Members.at(i).Fitness / sumOfFitness;
	//	}
	//}

	////// Then, make a vector of Genes that are going to be the parents.
	//Parents = std::vector<Member>();

	//// Push back two members of the population
	//Parents.push_back(pickParent(Pop.Members));
	//Parents.push_back(pickParent(Pop.Members));


	//// Gene permutation and mating
	//for (int i = 0; i < Pop.Members.size(); i++)
	//{
	//	for (int j = 0; j < Pop.Members.at(i).DNA.size(); j++)
	//	{
	//		int TempSelection = rand() % Parents.size();
	//		Pop.Members.at(i).DNA.at(j) = Parents.at(TempSelection).DNA.at(j);


	//		// random mutation rate
	//		if (rand() % 1000 < MutationRate)
	//		{
	//			Pop.Members.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;
	//		}

	//	}
	//}

}




Member Algorthims::pickParent(std::vector<Member> population)
{
	//std::default_random_engine generator;
	//std::random_device rd;     // only used once to initialise (seed) engine
	//std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	//// make random double between 0.0 and 1.0
	//std::uniform_real_distribution<> distribution(0.0, 1.0);
	
	std::random_device rd;


	std::mt19937 e2(rd());

	std::uniform_real_distribution<> distribution(0, 1);

	//generator.seed(distribution);

	int index = 0;

	auto r = distribution(e2);

	while (r > 0 && index < population.size())
	{
		r = r - population.at(index).probablity;
		
		index++;
	}
	index--;

	return population.at(index);
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

		std::cout << "Generation : " << generations << " Correct characters: " << Parents.at(0).Fitness / 10 << " Out of: " << DNASolution.size() << std::endl << "With Sequence : " << Parents.at(0).DNA.c_str() << std::endl;
		
	}
	std::cout << "Generation " << generations << " Evolved to the full sequence. " << std::endl;
	

}








Algorthims::~Algorthims()
{
}
