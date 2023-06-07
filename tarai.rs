use std::f64;
use std::time::Instant;

fn tarai(x: i32, y: i32, z: i32) -> i32 {
    if x <= y {
        return y;
    } else {
        return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
    }
}

fn main() {
    let n_iter = 10;
    let mut times: Vec<f64> = Vec::new();

    for _ in 0..n_iter {
        let start_time = Instant::now();
        tarai(13, 5, 0);
        let elapsed_time = start_time.elapsed();
        times.push(elapsed_time.as_secs_f64());
    }

    let average_time: f64 = times.iter().sum::<f64>() / n_iter as f64;
    let std_time: f64 = (times
        .iter()
        .map(|&x| (x - average_time).powi(2))
        .sum::<f64>()
        / n_iter as f64)
        .sqrt();

    println!("Rust version: {}", rust_version().unwrap_or_default());
    println!("Average elapsed_time: {} sec", average_time);
    println!("Standard deviation: {} sec", std_time);
}

fn rust_version() -> Option<String> {
    let output = std::process::Command::new("rustc")
        .arg("--version")
        .output()
        .ok()?;
    String::from_utf8(output.stdout).ok()
}
