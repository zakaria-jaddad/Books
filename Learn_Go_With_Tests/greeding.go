package main

import (
	"fmt"
	"testing"
)

func greeting(language string) string {

	greeting, exists := greetings[language]
	if exists {
		return greeting
	}
	return "Hello"
}

func Hello(name, language string) string {
	return fmt.Sprintf("%s, %s", greeting(language), name)
}

var greetings = map[string]string{"es": "Hola", "fr": "Bonjour"}

func TestHello(t *testing.T) {
	got := Hello("Zakaria", "es")
	want := "Hola, Zakaria"

	if got != want {
		t.Error("got " + got + "want " + want)
	}
}
