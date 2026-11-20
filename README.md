# RPL-TRUST

## Security-Aware Remote Attestation for RPL-Based IoT Networks

### 1. Project Description

RPL-TRUST is a research prototype focused on improving the security of IoT networks using the RPL routing protocol.

The project aims to explore remote attestation, firmware integrity verification, anomaly detection, and trust-based device admission mechanisms.

### 2. Project Objectives

1. Study security challenges in RPL-based IoT networks.
2. Simulate IoT network environments using Contiki-NG and Cooja.
3. Simulate abnormal network activity.
4. Develop firmware integrity verification.
5. Explore replay protection and firmware version validation.
6. Design trust-based device admission and quarantine.
7. Develop a security monitoring dashboard.

### 3. Technologies Used

- Contiki-NG
- Cooja Simulator
- C Programming
- RPL Protocol
- UDP Communication
- Docker
- Docker Compose
- Ubuntu on WSL2
- Git and GitHub
- Python (planned)
- SHA-256 (planned)
- Streamlit (planned)
- SQLite (planned)

### 4. Current Implementation

The current prototype includes:

- RPL-TRUST project workspace.
- Five-node Cooja simulation configuration.
- Contiki-NG based attacker simulation component.
- UDP-based simulated anomaly message.
- Periodic transmission of SIMULATED_ANOMALY.
- Firmware Makefile.
- Docker-based native firmware build environment.
- Docker Compose configuration.
- Automated Docker build script.

### 5. Docker Integration

Docker is integrated into the project to provide a reproducible firmware build environment.

Docker image:
contiker/contiki-ng:develop

Docker configuration:
docker-compose.yml

Automated build script:
scripts/docker-build.sh

Project directory is mounted inside the container at:
/workspace

Firmware working directory:
/workspace/firmware/device

#### Build Using Docker

Make sure Docker Desktop is running.

Run the following command from the project root:

./scripts/docker-build.sh

Docker Compose starts a temporary container and executes the Contiki-NG Makefile.

#### Verified Docker Tests

- Docker CLI and Engine successfully tested.
- Docker hello-world container executed successfully.
- Project directory successfully mounted inside Docker.
- Contiki-NG source files accessed inside the container.
- Native firmware compilation completed successfully.
- Docker Compose build workflow tested successfully.

#### Build Output

The native executable is generated at:

firmware/device/build/native/attacker.native

Current build target: native.

### 6. Project Structure

RPL-TRUST/
├── README.md
├── .gitignore
├── docker-compose.yml
├── RPL-TRUST-5-NODE.csc
├── firmware/
│   └── device/
│       ├── Makefile
│       └── attacker.c
├── scripts/
│   └── docker-build.sh
├── contiki-ng/
├── dashboard/
├── docs/
├── experiments/
├── results/
└── simulation/

Note: The Contiki-NG source repository is maintained separately and excluded from the RPL-TRUST Git repository.

### 7. Planned Development

The following features remain future development tasks:

1. Remote attestation request and response mechanism.
2. SHA-256 based firmware integrity verification.
3. Replay protection.
4. Firmware version validation.
5. Trust score calculation.
6. Device admission and quarantine.
7. Streamlit monitoring dashboard.
8. SQLite security event storage.
9. Experimental evaluation.

### 8. Project Status

Current stage: Initial simulation prototype with Docker-based native firmware build integration.

The anomaly simulation component has been compiled successfully using Docker and Contiki-NG.

Remote attestation, trust enforcement, and dashboard features are not yet fully implemented.

### 9. Future Scope

The project can be extended with automated firmware verification, secure device admission, attack detection, monitoring, and performance evaluation in simulated IoT networks.

### 10. Conclusion

RPL-TRUST aims to provide a security-aware framework for RPL-based IoT networks. The current work establishes the development environment, simulation configuration, anomaly-message prototype, and Docker-based firmware build workflow.

These components provide a foundation for future implementation of remote attestation and trust-based IoT security mechanisms.

### Disclaimer

This project is intended for academic research and controlled IoT network simulation.
