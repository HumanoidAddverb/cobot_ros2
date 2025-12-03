# Cobot Installation Instructions

## Prerequisites

Ensure you have the following zip files available:

- `cobot_ros2.zip` (or clone it from GitHub)
- `cobot_backend.zip`

## Installation Steps

### Step 1: Extract Archive Files

Unzip all the required files:
```bash
unzip cobot_ros2.zip
unzip cobot_backend.zip
```

### Step 2: Copy Backend Folders

Move the backend folders to the installation directory:
```bash
sudo mkdir -p /opt/addverb/
sudo cp -r cobot_backend /opt/addverb/
```

> **Note:** `sudo` privileges are required to write to `/opt/addverb/`


## Directory Structure

After installation, your directory structure should look like:
```
/opt/addverb/
└── cobot_backend/

~/cobot_ws/
└── cobot_ros2/
```
## To set up ROS2 work space
* Refer to the Setup.md file inside the cobot_ros2 directory to build and configure the ROS2 workspace.

## To control the robot
* Instructions for operating the robot are provided in the README_.md file located inside the cobot_ros2 directory.