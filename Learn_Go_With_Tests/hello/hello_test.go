package main

import "testing"

func TestHello(t *testing.T) {
	got := Hello("Zakaria")
	want := "Hello Zakaria!"

	if got != want {
		t.Errorf("got %q want %q ", got, want)
	}

}
