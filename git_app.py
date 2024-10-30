import os
import tkinter as tk
from tkinter import filedialog, messagebox, Listbox, simpledialog, StringVar
import git

class GitGUI:
    def __init__(self, master):
        self.master = master
        master.title("Simple Git GUI")
        master.geometry("600x500")
        master.configure(bg="#1c1c1c")  # Dark background

        self.repo_path = ""
        self.repo = None
        
        # Initialize commit message variable
        self.commit_message_var = StringVar()

        self.status_var = StringVar(value="Welcome to Simple Git GUI!")
        self.create_widgets()

    def create_widgets(self):
        # Title label
        self.title_label = tk.Label(self.master, text="Simple Git GUI", bg="#1c1c1c", fg="#00ff00", font=("Courier New", 16, "bold"))
        self.title_label.pack(pady=10)

        # Repository selection
        self.label = tk.Label(self.master, text="Select a Git Repository:", bg="#1c1c1c", fg="#ffffff", font=("Courier New", 12))
        self.label.pack(pady=10)

        self.select_button = tk.Button(self.master, text="Select Repository", command=self.select_repo, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.select_button.pack(pady=5)

        # Commit history
        self.commit_list_label = tk.Label(self.master, text="Commit History:", bg="#1c1c1c", fg="#ffffff", font=("Courier New", 12))
        self.commit_list_label.pack(pady=10)

        self.commit_listbox = Listbox(self.master, width=80, bg="#2d2d2d", fg="#00ff00", font=("Courier New", 10))
        self.commit_listbox.pack(pady=5)

        # Commit message input
        self.commit_message_entry = tk.Entry(self.master, textvariable=self.commit_message_var, bg="#2d2d2d", fg="#ffffff", font=("Courier New", 10))
        self.commit_message_entry.pack(pady=5)
        self.commit_message_entry.insert(0, "Enter commit message...")

        # Action buttons
        self.stage_button = tk.Button(self.master, text="Stage Changes", command=self.stage_changes, state=tk.DISABLED, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.stage_button.pack(pady=5)

        self.commit_button = tk.Button(self.master, text="Commit Changes", command=self.commit_changes, state=tk.DISABLED, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.commit_button.pack(pady=5)

        self.push_button = tk.Button(self.master, text="Push Changes", command=self.push_changes, state=tk.DISABLED, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.push_button.pack(pady=5)

        self.pull_button = tk.Button(self.master, text="Pull Changes", command=self.pull_changes, state=tk.DISABLED, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.pull_button.pack(pady=5)

        self.clone_button = tk.Button(self.master, text="Clone Repository", command=self.clone_repo, bg="#007700", fg="#ffffff", font=("Courier New", 10))
        self.clone_button.pack(pady=5)

        # Status bar
        self.status_bar = tk.Label(self.master, textvariable=self.status_var, bg="#1c1c1c", fg="#00ff00", font=("Courier New", 10))
        self.status_bar.pack(side=tk.BOTTOM, fill=tk.X)

    def select_repo(self):
        self.repo_path = filedialog.askdirectory()
        if self.repo_path and os.path.isdir(self.repo_path):
            self.repo = git.Repo(self.repo_path)
            self.update_commit_list()
            self.update_buttons_state(True)
            self.status_var.set(f"Selected repository: {self.repo_path}")
        else:
            messagebox.showerror("Error", "Please select a valid Git repository.")

    def update_commit_list(self):
        self.commit_listbox.delete(0, tk.END)
        for commit in self.repo.iter_commits():
            self.commit_listbox.insert(tk.END, f"{commit.hexsha[:7]} - {commit.message.strip()}")

    def update_buttons_state(self, state):
        buttons = [self.stage_button, self.commit_button, self.push_button, self.pull_button]
        for button in buttons:
            button.config(state=tk.NORMAL if state else tk.DISABLED)

    def stage_changes(self):
        try:
            self.repo.git.add(A=True)
            self.status_var.set("All changes staged.")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to stage changes: {str(e)}")

    def commit_changes(self):
        commit_message = self.commit_message_var.get() if self.commit_message_var.get() else "Updated by Simple Git GUI"
        try:
            self.repo.index.commit(commit_message)
            self.status_var.set("Changes committed.")
            self.update_commit_list()
        except Exception as e:
            messagebox.showerror("Error", f"Failed to commit changes: {str(e)}")

    def push_changes(self):
        try:
            self.repo.git.push()
            self.status_var.set("Changes pushed to remote repository.")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to push changes: {str(e)}")

    def pull_changes(self):
        try:
            self.repo.git.pull()
            self.status_var.set("Changes pulled from remote repository.")
            self.update_commit_list()
        except Exception as e:
            messagebox.showerror("Error", f"Failed to pull changes: {str(e)}")

    def clone_repo(self):
        repo_url = simpledialog.askstring("Clone Repository", "Enter the Git SSH URL of the GitHub repository:")
        if repo_url:
            target_dir = filedialog.askdirectory(title="Select Target Directory")
            if target_dir:
                try:
                    git.Repo.clone_from(repo_url, os.path.join(target_dir, os.path.basename(repo_url)))
                    self.status_var.set(f"Repository cloned to {target_dir}.")
                except Exception as e:
                    messagebox.showerror("Error", f"Failed to clone repository: {str(e)}")
            else:
                messagebox.showerror("Error", "Please select a valid target directory.")
        else:
            messagebox.showerror("Error", "Please enter a valid Git SSH URL.")

if __name__ == "__main__":
    root = tk.Tk()
    app = GitGUI(root)
    root.mainloop()
