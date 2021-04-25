package main
import _ "embed"
import "os"
//go:embed main.go
var q []byte
func main(){f,_:=os.Open("main.go");f.Write(q)}
