#pragma once
class Gene
{
public:
	Gene();
	Gene(int value, int fitness);
	~Gene();

	int CalcFitness(Gene* PerfectGene);
	int Value;
	int Fitness;

};

