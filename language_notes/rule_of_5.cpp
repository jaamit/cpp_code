class C {
  C(const C&) = default;               // Copy constructor
  C(C&&) = default;                    // Move constructor
  C& operator=(const C&) & = default;  // Copy assignment operator
  C& operator=(C&&) & = default;       // Move assignment operator
  virtual ~C() { }                     // Destructor
};
