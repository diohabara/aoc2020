use std::collections::HashMap;
use std::io::BufRead;
use std::path::Path;
use std::{fs::File, io::BufReader};

fn main() {
    let mut index_of_comp = HashMap::new();
    const TARGET: i32 = 2020;

    let filename = "./data/input";
    let file_path = Path::new(filename);
    let reader = get_file_reader(&file_path);

    for (index, num) in reader.lines().enumerate() {
        if let Ok(num) = num {
            index_of_comp.insert(TARGET - num.parse::<i32>().unwrap(), index);
        }
    }

    let reader = get_file_reader(&file_path);
    for (index, num) in reader.lines().enumerate() {
        if let Ok(num) = num {
            let num = num.parse::<i32>().unwrap();
            if index_of_comp.contains_key(&num) && index_of_comp[&num] != index {
                println!(
                    "I get {} when I multiply them together.",
                    (TARGET - num) * num
                );
                return;
            }
        }
    }
}

fn get_file_reader(path: &Path) -> impl BufRead {
    BufReader::new(File::open(path).unwrap())
}
