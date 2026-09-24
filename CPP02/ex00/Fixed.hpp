class Fixed {
	private:
		int _fixedPoint;
		static const int _frac_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};