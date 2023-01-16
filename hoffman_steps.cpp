#include <iostream>
using namespace std;

int *freq;

void display2d(int arr[][2], int len)
{
	for (int r = 0; r < len; r++)
	{
		cout << char(arr[r][0]) << " : " << arr[r][1] << endl;
	}
}

void display(int arr[], int len, int i = 0, int seq = 0)
{
	for (int r = i; r < i + seq; r++)
	{
		cout << arr[r] << endl;
	}
}

void sort(int arr[], int len)
{

	int minf, ix;
	int y = 0;
	for (int i = 0; i < len; i++)
	{
		minf = arr[i];
		for (y = i; y < len; y++)
		{
			if (arr[y] <= minf)
			{
				ix = y;
				minf = arr[y];
			}
		}
		arr[ix] = arr[i];
		arr[i] = minf;
	}
}

int main()
{

	int chars[256];
	for (int i = 0; i < 256; i++)
	{
		chars[i] = 0;
	}

	string nstr;
	cout << "Insert a string: ";
	getline(cin, nstr);
	unsigned char str[nstr.length()];

	for (int i = 0; i < nstr.length(); i++)
	{
		str[i] = nstr[i];
		chars[int(str[i])]++;
	}

	int len = 0;
	for (int i = 0; i < 256; i++)
	{
		if (chars[i] != 0)
		{
			len++;
		}
	}

	int char_freq[len][2];
	freq = new int[len];

	int in = 0;
	for (int i = 0; i < 256; i++)
	{
		if (chars[i] != 0)
		{
			freq[in] = chars[i];
			char_freq[in][0] = i;
			char_freq[in][1] = chars[i];
			in++;
		}
	}

	int minf, ix, ch;
	int y = 0;
	for (int i = 0; i < len; i++)
	{
		minf = char_freq[i][1];
		ch = char_freq[i][0];
		for (y = i; y < len; y++)
		{
			if (char_freq[y][1] <= minf)
			{
				ix = y;
				minf = char_freq[y][1];
				ch = char_freq[y][0];
			}
		}
		char_freq[ix][0] = char_freq[i][0];
		char_freq[i][0] = ch;
		char_freq[ix][1] = char_freq[i][1];
		char_freq[i][1] = minf;
	}

	display2d(char_freq, len);
	cout << "----------\n";

	sort(freq, len);
	int seq = 2;
	display(freq, len, 0, seq);
	cout << "----------\n";
	for (int i = 0; i < len - 1; i++)
	{

		int sum = freq[i] + freq[i + 1];
		freq[i] = 0;
		freq[i + 1] = sum;
		sort(freq, len);
		display(freq, len, i + 1, seq);
		cout << "----------\n";
	}

	int init_size = freq[len - 1] * 8;
	int final_size = len * 8 + freq[len - 1];
	int ch_bits[len];
	cout << "\n\nInsert the bits taken for the coding of each character:\n";
	for (int i = 0; i < len; i++)
	{

		cout << char(char_freq[i][0]) << " : ";
		cin >> ch_bits[i];
		final_size += char_freq[i][1] * ch_bits[i];
	}
	cout << "The initial size of the string was " << init_size << " bits, after the compression it is " << final_size << " bits.\n";
	if (final_size >= init_size)
	{
		cout << "The compression failed, hoffman's coding cannot compress this string.";
	}
	else
	{
		cout << "The compression was successful, the string has been compressed by " << init_size - final_size << " bits.\n";
	}

	return 0;
}