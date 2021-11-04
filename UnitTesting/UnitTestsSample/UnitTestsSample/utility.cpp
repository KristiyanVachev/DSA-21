static int GetAgeInDays(int age)
{
	if (age < 0)
	{
		return -1;
	}

	return age * 365;
}
