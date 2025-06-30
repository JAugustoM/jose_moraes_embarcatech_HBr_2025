{
  description = "Dev enviroment for compiling Pico C SDK projects";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    pkgs = nixpkgs.legacyPackages."x86_64-linux";
    pico-sdk = pkgs.pico-sdk.override { withSubmodules = true; };
  in 
  {
    devShells."x86_64-linux".default = pkgs.mkShell {
      packages = with pkgs; [ 
        cmake 
        ninja 
        gcc 
        gcc-arm-embedded 
        picotool 
        libusb1 
        newlib 
        just
        pico-sdk
      ];
      PICO_SDK_PATH = "${pico-sdk}/lib/pico-sdk";
      PROJECT_NAME = "robo_equilibrista";
    };
  };
}
