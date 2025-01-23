
# Why Do We Use `const` in Copy Constructor?

We use `const` in a copy constructor to ensure that the object being passed as an argument cannot be modified during the copy operation. The typical syntax of a copy constructor is:

```cpp
ClassName(const ClassName& obj);
```

Here’s why `const` is essential:

1. **Protects the Source Object**  
   The original object (`obj` in this case) being copied remains unchanged. Declaring it as `const` ensures that no accidental modifications occur to the source object inside the copy constructor.

2. **Allows Copying of `const` Objects**  
   If the parameter is not declared as `const`, the copy constructor cannot be called for `const` objects. For example:
   ```cpp
   const ClassName obj1;
   ClassName obj2 = obj1;  // Error if the copy constructor does not use `const`
   ```
   Declaring the parameter as `const` ensures that `const` objects can also be copied.

3. **Best Practice for Safety**  
   Using `const` reflects the intent that the source object is only used for reading values, aligning with the principle of minimizing side effects.

4. **Code Compatibility and Correctness**  
   Many standard containers and functions in C++ expect the copy constructor to accept a `const` reference. If the `const` qualifier is omitted, your class may not work correctly with standard library features.

### Additional Note:
By marking the parameter as `const`, you can only call `const` member functions of the source object, further ensuring that no unintended modifications are made.
