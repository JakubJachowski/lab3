// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);


int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;
	srand(time(NULL));

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	for(int i=0;i<n;i++)
	{
		if(i==0)
			vectorOfSlavs.push_back(&slavs[i]);//kiedy wektor nie ma jeszcze długości wstawiam pierwszą pozycje
		else                                   //ze slavs na poczatek wektora
			vectorOfSlavs.insert(vectorOfSlavs.begin() + rand()%vectorOfSlavs.size(), &slavs[i]);
	}

	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	for(vector <Slav *>::iterator it=vectorOfSlavs.begin(); it!=vectorOfSlavs.end();it++)
		cout<<(*it)->description();
	cout<<"\n";

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for(int i=0;i<n;i++)
		setOfSlavs.insert(vectorOfSlavs[i]);

	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	set <Slav *>::iterator it_sOS=setOfSlavs.begin();
	while(it_sOS!=setOfSlavs.end())
	{
		mapOfSlavs[*it_sOS]=*(it_sOS=(setOfSlavs.erase(it_sOS)));
		it_sOS=setOfSlavs.erase(it_sOS);
	}
	
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	for(map<Slav *, Slav *>::iterator it_mOS=mapOfSlavs.begin();it_mOS!=mapOfSlavs.end();it_mOS++)
		cout<<(it_mOS->first)->description()<<" <3"<<(it_mOS->second)->description()<<endl;

	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i=0;i<n;i++)
		queueOfSlavs.push(&slavs[i]);

	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	for(int i=0;i<n;i++)
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();	
	}


	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
	for(int i=0;i<n;i++)
	{
		cout<<stackOfSlavs.top()->description();
		stackOfSlavs.pop();
	}
	cout<<endl;

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}