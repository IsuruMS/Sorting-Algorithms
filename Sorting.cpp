#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0;

class MySortStrings
{
private:
	string sort, temp;
	char ch;

public:

	void SelectionSort(string arr[], int n)
	{
		int count1 = 0;
		for (int i = 0; i < n-1; i++)
		{
			int min = i;
			for (int j = i+1; j < n; j++)
			{
				if (arr[min] >arr[j])
				{
					min = j;
				}
				count1++;
			}
			if (min != i)
			{
				swap(arr[min], arr[i]);
			}
			
		}
		cout << "Selection Sort No. of Steps\t=\t" << count1 << endl << endl;
	}

	void InsertionSort(string arr[], int n)
	{

		for (int i = 1; i < n; i++)
		{
			int j = i;
			while (j >= 1)
			{
				count2++;
				if(arr[j-1]>arr[j])
					swap(arr[j-1], arr[j]);
				j--;
			}
		}
		cout << "Insertion Sort No. of Steps\t=\t" << count2 << endl << endl;
	}

	void BubbleSort(string arr[], int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0 ; j <(n-(i+1)); j++)
			{
				if (arr[j] > arr[j+1])
				{
					//cout << "done " << j << " times" << endl;
					swap(arr[j], arr[j + 1]);
				}
				count3++;
			}
		}
		cout << "Bubble Sort No. of Steps\t=\t" << count3 << endl << endl;
	}

	void mearge(string arr[], int l, int m, int r)
	{
		count4++;

		int i, j, k;
		int bound1 = m - l + 1;
		int bound2 = r - m;

		string left[5000], right[5000];

		for (i = 0; i < bound1; i++)
			left[i] = arr[l + i];
		for (i = 0; i < bound2; i++)
			right[i] = arr[m + i + 1];

		i = 0; j = 0; k = l;

		while (i < bound1 && j < bound2)
		{
			count4++;
			if (left[i] <= right[j])
			{
				arr[k] = left[i];
				i++;
			}
			else
			{
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		for (; i < bound1; )
		{
			arr[k] = left[i];
			i++;
			k++;
		}

		for (; j < bound2; )
		{
			arr[k] = right[j];
			j++;
			k++;
		}
		
	}
	
	void MeargeSort(string arr[], int l, int r)
	{
		count4++;
		int m = l + (r - l) / 2;
		if (l < r)
		{
			MeargeSort(arr, l, m);
			MeargeSort(arr, m + 1, r);
			mearge(arr, l, m, r);
			
		}
	}

	int partition(string arr[], int low, int high)
	{
		string pivot = arr[high];    // pivot 
		int i = (low - 1);  // Index of smaller element 
		count7++;

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or 
			// equal to pivot 
			if (arr[j] <= pivot)
			{
				i++;    // increment index of smaller element 
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1);
		}

	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low  --> Starting index,
	high  --> Ending index */
	void quickSort(string arr[], int low, int high)
	{
		count7++;
		if (low < high)
		{
			/* pi is partitioning index, arr[p] is now at right place */
			int pi = partition(arr, low, high);
			// Separately sort elements before 
			// partition and after partition 
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	
};

int main()
{
	const int n = 10000;
	string str, arr[n];
	
	MySortStrings string1;
	
	ifstream doc("Words.txt");

	for (int i = 0; i < n; i++)
	{
		getline(doc, str);
		arr[i] = str;
	}
	string1.BubbleSort(arr, n);
	string1.InsertionSort(arr, n);
	string1.SelectionSort(arr, n);
	string1.MeargeSort(arr, 0, n-1);
	cout << "Mearge Sort - partitioning part - No. of Steps\t=\t" << count4 << endl << endl;
	string1.quickSort(arr, 0, n - 1);
	cout << "Quick Sort - partitioning - No. of Steps\t=\t" << count7 << endl << endl;

	doc.close();

	system("pause");
	return 0;
}