package main

import "fmt"
import "bytes"
import "os"
import "os/exec"
import "log"
// import "github.com/robfig/cron"

func main() {
    var user = os.Args[1]
    cmd := exec.Command("sh", "-c", "crontab -u " + user + " -l")
    var out bytes.Buffer
    cmd.Stdout = &out
    err := cmd.Run()
    if err != nil {
		log.Fatal(err)
	}
    // fmt.Printf("%s\n", out)
    fmt.Print(out)
}
