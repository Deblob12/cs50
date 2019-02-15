import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request, url_for

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")

# another route for form


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")

# route for form


@app.route("/form", methods=["POST"])
def post_form():
    if not request.form.get("emaill") or not request.form.get("app") or not request.form.get("drinkk"):
        return render_template("error.html", message="You did not complete the form!")
    with open("registered.csv", "a") as file:
        writer = csv.DictWriter(file, fieldnames=["email", "appetizer", "drinks", "diet", "child"])
        writer.writerow({"email": request.form.get("emaill"), "appetizer": request.form.get("app"), "drinks": request.form.get(
            "drinkk"), "diet": request.form.get("diett"), "child": request.form.get('children')})
    return redirect(url_for('get_sheet'))

# route for sheet


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("registered.csv", "r") as file:
        reader = csv.DictReader(file)
        rsvp = list(reader)
    return render_template("sheet.html", rsvp=rsvp)
