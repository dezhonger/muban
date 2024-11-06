int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}



// structure format
struct Prime {
	vector<int> primes;
	vector<bool> st;
	int n;
	
	Prime(int n) :n(n) {
		st = vector<bool>(n + 1, false);
	}

	void get_primes()
	{
		for (int i = 2; i <= n; i ++ )
		{
			if (!st[i]) primes.push_back(i);
			for (int j = 0; primes[j] <= n / i; j ++)
			{
				st[primes[j] * i] = true;
				if (i % primes[j] == 0) break;
			}
		}
	}
	
	int get_num() {
		return primes.size();
	}
	
	void print() {
		cout << "num: " << get_num() << endl;
		for (int i = 0; i < get_num(); i++) {
			cout << primes[i] << " ";
		}
		cout << endl;
	}
	
	void print(int m) {
		cout << "num: " << get_num() << endl;
		for (int i = 0; i < min(m, get_num()); i++) {
			cout << primes[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Prime p(10000000);
	p.get_primes();
	p.print(25);
	return 0;
}
