use std::collections::HashMap;
use std::io::BufRead;
use std::path::Path;
use std::{fs::File, io::BufReader};

fn main() {
    solve_first();
    solve_second();
}

fn solve_first() {
    let filename = "./data/input";
    let target = 2020;
    let (num1, num2) = two_entries_with_target_sum(filename, target);
    if num1 == -1 && num2 == -1 {
        println!("First: I've failed to find the entries")
    } else {
        println!(
            "First: I get {} when I multiply them together.",
            num1 * num2
        );
    }
}

fn solve_second() {
    let filename = "./data/input";
    let target = 2020;
    let (num1, num2, num3) = three_entries_with_target_sum(filename, target);
    if num1 == -1 && num2 == -1 && num3 == -1 {
        println!("Second: I've failed to find the entries")
    } else {
        println!(
            "Second: I get {} when I multiply them together.",
            num1 * num2 * num3
        );
    }
}

fn get_file_reader(filename: &str) -> impl BufRead {
    let file_path = Path::new(filename);
    BufReader::new(File::open(file_path).unwrap())
}

fn two_entries_with_target_sum(filename: &str, target: i32) -> (i32, i32) {
    let mut index_of_comp = HashMap::new();
    let reader = get_file_reader(filename);

    for (index, num) in reader.lines().enumerate() {
        if let Ok(num) = num {
            index_of_comp.insert(target - num.parse::<i32>().unwrap(), index);
        }
    }

    let reader = get_file_reader(filename);
    for (index, num) in reader.lines().enumerate() {
        if let Ok(num) = num {
            let num: i32 = num.parse().unwrap();
            if index_of_comp.contains_key(&num) && index_of_comp[&num] != index {
                return (target - num, num);
            }
        }
    }
    (-1, -1)
}

fn three_entries_with_target_sum(filename: &str, target: i32) -> (i32, i32, i32) {
    let mut index_of_comp = HashMap::new();
    let reader = get_file_reader(filename);

    for (index, num) in reader.lines().enumerate() {
        if let Ok(num) = num {
            index_of_comp.insert(target - num.parse::<i32>().unwrap(), index);
        }
    }

    let reader1 = get_file_reader(filename);
    for (i, num1) in reader1.lines().enumerate() {
        if let Ok(num1) = num1 {
            let num1: i32 = num1.parse().unwrap();
            let reader2 = get_file_reader(filename);
            for (j, num2) in reader2.lines().enumerate() {
                if let Ok(num2) = num2 {
                    let num2: i32 = num2.parse().unwrap();
                    if index_of_comp.contains_key(&(num1 + num2))
                        && index_of_comp[&(num1 + num2)] != i
                        && index_of_comp[&(num1 + num2)] != j
                    {
                        return (num1, num2, target - num1 - num2);
                    }
                }
            }
        }
    }
    (-1, -1, -1)
}
