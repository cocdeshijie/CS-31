#include <iostream>
#include <string>
using namespace std;

int main()
{
	string model, color, error_type;
	double price;
	int memory;

	cout << "What type of iPhone do you want? ";
	getline(cin, model);
	cout << "What color do you want? ";
	getline(cin, color);
	cout << "How much memory do you want? ";
	cin >> memory;

	// model must be iPhone 12, iPhone 12 Mini, iPhone 12 Pro, or iPhone 12 Pro Max
	if ((model == "iPhone 12") || (model == "iPhone 12 Mini") || (model == "iPhone 12 Pro") || (model == "iPhone 12 Pro Max"))
	{
		//continue
	}
	else
	{
		error_type = "model";
	}

	//iPhone 12
	if (model == "iPhone 12")
	{
		//if color dont match return color error
		if ((color == "White") || (color == "Black") || (color == "Blue") || (color == "Green") || (color == "Red") || (color == "Purple"))
		{
			//if memory dont match return memory error
			switch (memory)
			{
			case 64:
				price = 799.00;
				break;
			case 128:
				price = 849.00;
				break;
			case 256:
				price = 949.00;
				break;
			default:
				error_type = "memory";
				break;
			}
		}
		else
		{
			error_type = "color";
		}
	}

	//iPhone 12 Mini
	if (model == "iPhone 12 Mini")
	{
		if ((color == "White") || (color == "Black") || (color == "Blue") || (color == "Green") || (color == "Red") || (color == "Purple"))
		{
			switch (memory)
			{
			case 64:
				price = 699.00;
				break;
			case 128:
				price = 749.00;
				break;
			case 256:
				price = 849.00;
				break;
			default:
				error_type = "memory";
				break;
			}
		}
		else
		{
			error_type = "color";
		}
	}

	//iPhone 12 Pro
	if (model == "iPhone 12 Pro")
	{
		if ((color == "Graphite") || (color == "Silver") || (color == "Gold") || (color == "Blue"))
		{
			switch (memory)
			{
			case 128:
				price = 999.00;
				break;
			case 256:
				price = 1099.00;
				break;
			case 512:
				price = 1299.00;
				break;
			default:
				error_type = "memory";
				break;
			}
		}
		else
		{
			error_type = "color";
		}
	}

	//iPhone 12 Pro Max
	if (model == "iPhone 12 Pro Max")
	{
		if ((color == "Graphite") || (color == "Silver") || (color == "Gold") || (color == "Blue"))
		{
			switch (memory)
			{
			case 128:
				price = 1099.00;
				break;
			case 256:
				price = 1199.00;
				break;
			case 512:
				price = 1399.00;
				break;
			default:
				error_type = "memory";
				break;
			}
		}
		else
		{
			error_type = "color";
		}
	}


	//no error result
	if (error_type.empty())
	{
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "Your " << color << " " << model << " costs $" << price << "." << endl;
		return (0);
	}
	//error result
	else
	{
		cout << "Your " << error_type << " selection is not valid!" << endl;
		return (1);
	}
}