#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

//	12:00:00PM 			is 12:00:00 on a 24-hour clock
string timeConversion(string s)
{
	string am_pm = s.substr(8,2);
	string hour = s.substr(0, 2);
	short		hour_for_converting = stoi(hour);

	if (am_pm == "AM" && hour == "12")
		hour = "00";
	else if (am_pm == "PM")
	{
		if (hour != "12")
		{
			hour_for_converting += 12;
			hour = to_string(hour_for_converting);
		}
	}
	return (hour + s.substr(2, 6));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
