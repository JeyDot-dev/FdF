unsigned int	ft_abs(int n, char neg)
{
	if (neg == '-')
	{
		if (n > 0)
			n *= -1;
	}
	else
	{
		if (n < 0)
			n *= -1;
	}
	return (n);
}
