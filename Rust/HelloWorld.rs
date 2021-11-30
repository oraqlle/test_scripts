use std::{thread, time};

fn main()
{
    println!("Hello World");
    thread::sleep(time::Duration::from_secs(5));
}