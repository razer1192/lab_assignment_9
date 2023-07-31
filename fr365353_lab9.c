#include <stdio.h>
//linked list node
/*
struct Node{
	int next;
	struct RecordType data;
};*/
// RecordType
struct RecordType
{
	
	int		id;
	char	name;
	int		order; 

};

// Fill out this structure
struct HashType
{
	/*
	struct Node hashTable[15];
	*/
	int next;
	struct RecordType data;
};

// Compute the hash function
int hash(int x)
{
	//seperate chaining means I need to use linked lists in the hash table
	int tmp = x%15;
	return tmp;


}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;

	for (i=0;i<hashSz;++i)
	{
		// if index is occupied with any records, print all
	}
}

int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;

	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);
	// Your hash implementation
	int hashed;
	struct RecordType record;
	
	struct HashType hashTable[15];
	//should store the records in the hash table
	for(int i = 0; i < recordSz; i++){
		record = pRecords[i];
		hashed = hash(record.id);
		struct HashType * cursor;
		cursor = &hashTable[hashed];
		while ((cursor != NULL) && (cursor->next != NULL)){
			cursor = cursor->next;
		}
		cursor->next = (struct HashType*)malloc(sizeof( struct HashType));
		cursor = cursor->next;
		cursor->data = record;
	}
}
//table size should be 15
