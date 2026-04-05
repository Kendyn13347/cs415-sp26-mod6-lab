// ============================================================
// Part 1: Primitive Data Types (Task 1B)
// ============================================================
fn part1_primitives() {
    let a: i32 = 10;           // 32-bit signed integer
    let b: f32 = 3.14;         // 32-bit float
    let c: f64 = 3.1415926535; // 64-bit float
    let flag: bool = true;     // Boolean
    let ch: char = 'A';        // 4-byte Unicode scalar value
    println!("{} {} {} {} {}", a, b, c, flag, ch);
}

// ============================================================
// Part 2: Strings and Memory (Task 2B)
// ============================================================
fn part2_strings() {
    // String::from allocates memory on the heap
    let mut s = String::from("Hello");
    s.push_str(" World"); // Modifies the heap data
    println!("{}", s);
}

// ============================================================
// Part 3A: Static Arrays
// ============================================================
fn part3a_static() {
    let arr = [1,2,3,4,5];
    for x in &arr { print!("{} ", x); }
    println!();
    println!("Length: {}", arr.len());
}

// ============================================================
// Part 3B: Dynamic Arrays
// ============================================================
fn part3b_dynamic() {
    let mut vec: Vec<i32> = vec![10, 20, 30, 40, 50];
    vec.push(60);
    for x in &vec { print!("{} ", x); }
    println!();
    println!("Length: {}", vec.len());
    // Memory automatically freed when vec goes out of scope
}

// ============================================================
// Part 4: Records (Structs)
// ============================================================
struct Person {
    name: String,
    age: i32,
    height: f64,
}

fn part4_structs() {
    let p = Person {
        name: String::from("Alice"),
        age: 30,
        height: 5.6,
    };
    println!("Name: {}, Age: {}, Height: {}", p.name, p.age, p.height);
    println!("Struct size: {} bytes", std::mem::size_of::<Person>());
}

// ============================================================
// Part 5: Borrowing
// ============================================================
fn part5_borrowing() {
    let x = 42;
    let r = &x;           // Immutable reference
    println!("Value: {}", x);
    println!("Via reference: {}", r);
    println!("Address: {:p}", r);

    let mut y = 10;
    {
        let r_mut = &mut y; // Mutable reference
        *r_mut += 1;
        println!("Modified value: {}", r_mut);
    }
    println!("y after: {}", y);
}

// ============================================================
// Challenge 2: Float Precision Loss
// ============================================================
fn challenge2_precision() {
    let large: f32 = 1e38_f32;
    let small: f32 = 1.0_f32;
    let result: f32 = large + small;
    println!(
        "large + small == large? {}",
        if result == large { "YES — precision lost!" } else { "No" }
    );
}

// ============================================================
// Challenge 4: Ownership Move
// ============================================================
fn challenge4_ownership() {
    let s1 = String::from("hello");
    let s2 = s1; // s1 is MOVED into s2; s1 is no longer valid
    // println!("{}", s1); // COMPILE ERROR: value borrowed after move
    println!("s2 = {} (s1 was moved here)", s2);
}

// ============================================================
fn main() {
     part1_primitives();
     part2_strings();
     part3a_static();
     part3b_dynamic();
     part4_structs();
     part5_borrowing();
     challenge2_precision();
    challenge4_ownership();

    // Uncomment below to observe a controlled panic from out-of-bounds:
    // let arr = [1, 2, 3, 4, 5];
    // println!("{}", arr[10]);
}