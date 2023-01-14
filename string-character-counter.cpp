#include <iostream>
using namespace std;

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

	int in = 0;
	for (int i = 0; i < 256; i++)
	{
		if (chars[i] != 0)
		{
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
			if (char_freq[y][1] < minf)
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

	for (int r = 0; r < len; r++)
	{
		cout << char(char_freq[r][0]) << " : " << char_freq[r][1] << endl;
	}

	return 0;
}
