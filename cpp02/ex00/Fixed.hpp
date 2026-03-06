#ifndef FIXED_FPP
#define FIXED_FPP

class Fixed
{
private:
	/* data */
public:
	Fixed(int n);
	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
};

#endif